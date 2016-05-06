
#include "UI.hpp"

#include <string.h>
#include <time.h>
#include "GUI.hpp"

UI::UI() {
  // must initialize uM and fM reading from BD/conf files
  this->uM = new UserManager();
  this->fM = new FileManager();
  this->logged = NULL;
}

void UI::run() {
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
        logged->addUser(uM, uName, uPswd, GUI::getUserResp());
        GUI::userCreated();
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
        uName = GUI::getFileName("list logs");
        file = fM->getFile(uName);
        delete uName;
        
        if (file == NULL) {
          GUI::dontExist();
          continue;
        }
        
        listLogs = file->listLogs();
        
        itLog = listLogs->begin();
        GUI::clearScreen();
        for (; itLog != listLogs->end(); ++itLog) {
          GUI::listLog((*itLog)->getTime(), (*itLog)->getOwner(), (*itLog)->getChange());
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
        
      default:
        continue;
    }
  }
}

void UI::login() {
  string *sUser, *sPasswd;
  
  sUser = GUI::getUserLogin();
  sPasswd = GUI::getPswdLogin();
  
  this->logged = uM->login(sUser, sPasswd);
  
  if (this->logged == NULL) {
    cout << "User name or password doesnt match" << endl; // <<--check
    GUI::pause();
  }
  
  delete sUser;
  delete sPasswd;
}
