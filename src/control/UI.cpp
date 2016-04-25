
#include "UI.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    
    UI::clearScreen();
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
      logged->addUser(uM);
    }
    else if (!strcmp(command, "remove user")) {
      logged->removeUser(uM);
    }
    else if (!strcmp(command, "add file")) {
      logged->addFile(fM);
    }
    else if (!strcmp(command, "remove file")) {
      logged->removeFile(fM);
    }
    else if (!strcmp(command, "modify file")) {
      UI::clearScreen();
      cout << "Insert file name to modify" << endl;
      cin.getline(command, sizeof(command));
      string *sName = new string(command);
      File *file = fM->getFile(sName);
      delete sName;
      
      UI::clearScreen();
      if (file == NULL) {
        cout << "File dont exist." << endl;
        UI::pause();
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
      
      UI::clearScreen();
      std::list<string*>::iterator it=listFiles->begin();
      if (it == listFiles->end()) {
        cout << "No files." << endl;
      }
      for (; it != listFiles->end(); ++it) {
        cout << (*it)->c_str() << endl;
      }
      delete listFiles;
      UI::pause();
    }
    else if (!strcmp(command, "list logs")) {
      UI::clearScreen();
      cout << "What file you want to list logs." << endl;
      cin.getline(command, sizeof(command));
      string *sName = new string(command);
      File *file = fM->getFile(sName);
      delete sName;
      
      UI::clearScreen();
      if (file == NULL) {
        cout << "File dont exist." << endl;
        UI::pause();
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
      UI::pause();
    }
    else if (!strcmp(command, "exit")) {
      this->logged = NULL;
    }
  }
}

void UI::login() {
  char user[100], passwd[100];
  string *sUser, *sPasswd;
  UI::clearScreen();
  cout << "User name:" << endl;
  cin.getline(user, sizeof(user));
  cout << "Password" << endl;
  cin.getline(passwd, sizeof(passwd));
  
  sUser = new string(user);
  sPasswd = new string(passwd);
  
  this->logged = uM->login(sUser, sPasswd);
  
  if (this->logged == NULL) {
    cout << "User name or password doesnt match" << endl; // <<--check
    UI::pause();
  }
  
  delete sUser;
  delete sPasswd;
}

void UI::clearScreen() {
  cout << "\033[H\033[2J" << endl;
  return;
}

void UI::pause() {
  fgetc(stdin); // pause
  return;
}
