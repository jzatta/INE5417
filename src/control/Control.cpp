
#include "Control.hpp"

#include <string.h>
#include <time.h>
#include "GUI.hpp"

Control::Control() {
// must initialize uM and fM reading from BD/conf files
  this->uM = new UserManager();
  this->fM = new FileManager();
  this->logged = NULL;
}

void Control::run() {
  while (this->logged == NULL) {
    this->login();
  }
  while (this->logged != NULL) {
    string *uName;
    string *uPswd;
    string *fName;
    string *fLog;
    string *ret;
    File *file;
    list<string*> *listOfFiles;
    list<Log*> *listLogs;
    std::list<Log*>::iterator itLog;
  
    switch (GUI::mainScreen()) {
      case 1: // add user
        uName = GUI::getUserName("create");
        uPswd = GUI::getUserPswd();
        ret = logged->addUser(uM, uName, uPswd, GUI::getUserResp());
        if (!ret->compare("access denied")) {
          GUI::permissionException();
        } 
        else if (!ret->compare("created")) {
          GUI::userCreated();
        }
        delete ret;
        delete uName;
        continue;
        
      case 2: // remove user
        uName = GUI::getUserName("remove");
        ret = logged->removeUser(uM, uName);
        if (!ret->compare("access denied")) {
          GUI::permissionException();
        } 
        else if (!ret->compare("removed")) {
          GUI::userRemoved();
          if (!logged->getName()->compare(*uName)) {
            logged = NULL;
          break;
          }
        }
        else if (!ret->compare("don't exist")) {
          GUI::dontExist();
        }
        delete ret;
        delete uName;
        continue;
      
      case 3: // add file
        logged->addFile(fM, GUI::getFileName("create"));
        continue;
      
      case 4: // remove file
        logged->removeFile(fM, GUI::getFileName("remove"));
        continue;
      
      case 5: // modify file
        fName = GUI::getFileName("modify");
        file = fM->getFile(fName);
        delete fName;
      
        if (file == NULL) {
          GUI::dontExist();
          continue;
        }
      
        file->modify();
        fLog = GUI::getChanges();
        file->addLog(new Log(fLog, this->logged));
        continue;
      
      case 6: // list files
        listOfFiles = logged->listFile(fM);
        GUI::listStrings(listOfFiles);
        delete listOfFiles;
        continue;
      
      case 7: // list logs
        fName = GUI::getFileName("list logs");
        file = fM->getFile(fName);
        delete fName;
      
        if (file == NULL) {
          GUI::dontExist();
          continue;
        }
      
        listLogs = file->listLogs();
      
        itLog = listLogs->begin();
        GUI::clearScreen();
        for (; itLog != listLogs->end(); ++itLog) {
          GUI::listLog((*itLog)->getTime(), (*itLog)->getOwner(), (*itLog)->getChange(), -1);
        }
        GUI::pause();
        continue;

      case 8: // change user
        this->logged = NULL;
        this->login();
        continue;
      
      case 9: // exit
        this->logged = NULL;
        break;
      
      case 10: // restore file
        this->restore();
        continue;
      
      case 11: // check diff
        this->diff();
        continue;


      default:
        continue;
    }
  }
}

void Control::login() {
  string *sUser, *sPasswd;

  do {
    sUser = GUI::getUserLogin();
    sPasswd = GUI::getPswdLogin();
  
    this->logged = uM->login(sUser, sPasswd);
  
    if (this->logged == NULL) {
      cout << "User name or password doesnt match" << endl; // <<--check
      GUI::pause();
    } else {
      GUI::showLogged(sUser);
    }
    delete sUser;
    delete sPasswd;
  } while (this->logged == NULL);
}

void Control::restore() {
  string *fName;
  list<Log*> *listLogs;
  std::list<Log*>::iterator itLog;
  
  fName = GUI::getFileName("restore");
  listLogs = fM->listLogs(fName);

  if (listLogs == NULL) {
    GUI::dontExist();
    return;
  }

  GUI::clearScreen();
  itLog = listLogs->begin();
  for (; itLog != listLogs->end(); ++itLog) {
    GUI::listLog((*itLog)->getTime(), (*itLog)->getOwner(), (*itLog)->getChange(), (*itLog)->getSequence());
  }
  
  int ver;
  ver = GControl::getVersion();
  if (fM->restore(fName, this->logged, ver)) {
    GUI::dontExist();
  }
  delete fName;
}

void Control::diff() {
  string *fName;
  list<Log*> *listLogs;
  std::list<Log*>::iterator itLog;
  
  fName = GUI::getFileName("to check differences between the previous one");
  listLogs = fM->listLogs(fName);

  if(listLogs == NULL) {
    GUI::dontExist();
    return;
  }
  int _ver;
  itLog = listLogs->begin();
  GUI::clearScreen();
  for(; itLog != listLogs->end(); ++itLog) {
    GUI::listLog((*itLog)->getTime(), (*itLog)->getOwner(), (*itLog)->getChange(), (*itLog)->getSequence());
  }
  
  _ver = GUI::getVersionDiff();
  if(_ver <= 1) {
    GUI::dontExist();
    return;
  }
  string *f1Name, *f2Name;
  f1Name = fM->fileLogVersion(fName, _ver);
  f2Name = fM->fileLogVersion(fName, _ver-1);
  GUI::getDiff(*f1Name, *f2Name);
  delete fName;
}
