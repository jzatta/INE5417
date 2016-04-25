
#include "UI.hpp"

#include <stdio.h>
#include <string.h>

UI::UI() {
  // must initialize uM and fM reading from BD/conf files
  this->uM = new UserManager();
//   this->fM = new FileManager();
  this->logged = NULL;
}

void UI::run() {
  while (true) {
    char command[100];
    
    this->login();
    
    cout << "\033[H\033[2J" << endl;
    cout << "list of commands:" << endl;
    cout << "add user" << endl;
    cout << "remove user" << endl;
    cout << "add file" << endl;
    cout << "remove file" << endl;
    cout << "exit" << endl;
    
    cin.getline(command, sizeof(command));
    if (!strcmp(command, "add user")) {
      cout << "addeu user" << endl;
      fgetc(stdin); // pause
    }
    else if (!strcmp(command, "remove user")) {
      cout << "removeu user" << endl;
      fgetc(stdin); // pause
    }
    else if (!strcmp(command, "add file")) {
      cout << "addeu file" << endl;
      fgetc(stdin); // pause
    }
    else if (!strcmp(command, "remove file")) {
      cout << "removeu file" << endl;
      fgetc(stdin); // pause
    }
    else if (!strcmp(command, "exit")) {
      this->logged = NULL;
    }
  }
}

void UI::login() {
  while (this->logged == NULL) {
    char user[100], passwd[100];
    string *sUser, *sPasswd;
    cout << "\033[H\033[2J" << endl;
    cout << "User name:" << endl;
    cin.getline(user, sizeof(user));
    cout << "Password" << endl;
    cin.getline(passwd, sizeof(passwd));
    
    sUser = new string(user);
    sPasswd = new string(passwd);
    
    this->logged = uM->login(sUser, sPasswd);
    
    if (this->logged == NULL) {
      cout << "User name or password doesnt match" << endl; // <<--check
      fgetc(stdin); // pause
    }
    
    delete sUser;
    delete sPasswd;
  }
}
