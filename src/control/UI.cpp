
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
  while (true) {
    char command[100];
    
    while (this->logged == NULL) {
      this->login();
    }
    
    GUI::clearScreen();
    cout << "list of commands:" << endl;
    cout << "add user" << endl;
    cout << "remove user" << endl;
    cout << "add file" << endl;
    cout << "remove file" << endl;
    cout << "modify file" << endl;
    cout << "list files" << endl;
    cout << "list logs" << endl;
    cout << "exit" << endl;
    
    cin.getline(command, sizeof(command));
    
    if (!strcmp(command, "add user")) {
      logged->addUser(uM, GUI::getUserName("create"), GUI::getUserPswd(), GUI::getUserResp());
      GUI::userCreated();
    }
    else if (!strcmp(command, "remove user")) {
      logged->removeUser(uM, GUI::getUserName("remove"));
    }
    else if (!strcmp(command, "add file")) {
      logged->addFile(fM, GUI::getFileName("create"));
    }
    else if (!strcmp(command, "remove file")) {
      logged->removeFile(fM, GUI::getFileName("remove"));
    }
    else if (!strcmp(command, "modify file")) {
      GUI::clearScreen();
      cout << "Insert file name to modify" << endl;
      cin.getline(command, sizeof(command));
      string *sName = new string(command);
      File *file = fM->getFile(sName);
      delete sName;
      
      GUI::clearScreen();
      if (file == NULL) {
        cout << "File dont exist." << endl;
        GUI::pause();
        continue;
      }
      
      file->modify();
      
      cout << "Tell me what changes you do" << endl;
      cin.getline(command, sizeof(command));
      
      file->addLog(new Log(command, this->logged));
      
    }
    else if (!strcmp(command, "list files")) {
      list<string*> *listFiles;
      listFiles = logged->listFile(fM);
      
      GUI::clearScreen();
      std::list<string*>::iterator it=listFiles->begin();
      if (it == listFiles->end()) {
        cout << "No files." << endl;
      }
      for (; it != listFiles->end(); ++it) {
        cout << (*it)->c_str() << endl;
      }
      delete listFiles;
      GUI::pause();
    }
    else if (!strcmp(command, "list logs")) {
      GUI::clearScreen();
      cout << "What file you want to list logs." << endl;
      cin.getline(command, sizeof(command));
      string *sName = new string(command);
      File *file = fM->getFile(sName);
      delete sName;
      
      GUI::clearScreen();
      if (file == NULL) {
        cout << "File dont exist." << endl;
        GUI::pause();
        continue;
      }
      
      list<Log*> *listLogs;
      listLogs = file->listLogs();
      
      std::list<Log*>::iterator it=listLogs->begin();
      for (; it != listLogs->end(); ++it) {
        cout << asctime(localtime((*it)->getTime()));
        cout << (*it)->getOwner()->c_str() << endl << endl;
        cout << (*it)->getChange()->c_str() << endl << endl;
      }
      GUI::pause();
    }
    else if (!strcmp(command, "exit")) {
      this->logged = NULL;
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
