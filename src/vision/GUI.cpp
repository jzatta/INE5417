#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "GUI.hpp"

using namespace std;

void GUI::permissionException() {
  GUI::clearScreen();
  cout << "Access Denied!" << endl;
  GUI::pause();
}

string *GUI::getFileName(const char *_param) {
  char name[100];
  GUI::clearScreen();
  cout << "Insert file name to " << _param << endl;
  cin.getline(name, sizeof(name));
  return new string(name);
}

string *GUI::getUserName(const char *_param) {
  char name[100];
  GUI::clearScreen();
  cout << "Insert user name to " << _param << endl;
  cin.getline(name, sizeof(name));
  return new string(name);
}

string *GUI::getUserPswd() {
  char *password; // char* cuz getpass(string) returns char*
  password  = new char[100];
  GUI::clearScreen();
  password = getpass("Insert Password\n"); // get the password without echoing in terminal
  return new string(password);
}

bool GUI::getUserResp() {
	char super[5];
	GUI::clearScreen();
	cout << "Is superuser (yes/no)" << endl;
  cin.getline(super, sizeof(super));
  if (!strcmp(super, "yes")) {
    return true;
  }
  return false;
}

void GUI::userCreated() {
	GUI::clearScreen();
	cout << "User created" << endl;
  GUI::pause();
}

void GUI::fileCreated() {
	GUI::clearScreen();
	cout << "File created" << endl;
	GUI::pause();
}

void GUI::userRemoved() {
	GUI::clearScreen();
	cout << "User removed" << endl;
	GUI::pause();
}

void GUI::fileRemoved() {
	GUI::clearScreen();
	cout << "File removed" << endl;
	GUI::pause();
}

void GUI::deleteNotification(string *_type, string *_verify) {
	GUI::clearScreen();
  cout << *_type + " " + *_verify << endl;
  GUI::pause();
}

void GUI::dontExist() {
  cout << "Dont exist." << endl;
  GUI::pause();
}

string *GUI::getUserLogin() {
  char user[100];
  GUI::clearScreen();
  cout << "User name:" << endl;
  cin.getline(user, sizeof(user));
  return new string(user);
}

string *GUI::getPswdLogin() {
  char *passwd;
  passwd = new char[100];
  GUI::clearScreen();
  passwd = getpass("Password\n"); // get the password without echoing in terminal
  return new string(passwd);
}

string *GUI::getChanges() {
  char change[250];
  GUI::clearScreen();
  cout << "Tell me what changes you do" << endl;
  cin.getline(change, sizeof(change));
  return new string(change);
}

int GUI::getVersion() {
  char name[100]; int ret;
  cout << "Insert version file to restore:" << endl;
  cin.getline(name, sizeof(name));
  ret = atoi(name);
  if (ret == 0) {
    int i;
    for (i = 0; i < 100; i++) {
      if (name[i] == '0') {
        continue;
      }
      else if (name[i] == '\0') {
        break;
      }
      else return -1;
    }
  }
  return ret;
}

int GUI::getVersionDiff() {
  char name[100]; 
  int ret;
  cout << "Insert version file to check differences:" << endl;
  cin.getline(name, sizeof(name));
  ret = atoi(name);
  if(ret <= 0) {
    return -1;
  }
  return ret;
}

void GUI::clearScreen() {
  cout << "\033[H\033[2J" << endl;
  return;
}

void GUI::pause() {
  fgetc(stdin); // pause
  return;
}

int GUI::mainScreen() {
  char command[50];
  GUI::clearScreen();
  cout << "list of commands:" << endl;
  cout << "add user" << endl;
  cout << "remove user" << endl;
  cout << "add file" << endl;
  cout << "remove file" << endl;
  cout << "modify file" << endl;
  cout << "check diff" << endl;
  cout << "restore file" << endl;
  cout << "list files" << endl;
  cout << "list logs" << endl;
  cout << "change user" << endl;
  cout << "execute" << endl;
  cout << "view content" << endl;
  cout << "exit" << endl;
  
  cin.getline(command, sizeof(command));
  
  if (!strcmp(command, "add user")) {
    return 1;
  }
  else if (!strcmp(command, "remove user")) {
    return 2;
  }
  else if (!strcmp(command, "add file")) {
    return 3;
  }
  else if (!strcmp(command, "remove file")) {
    return 4;
  }
  else if (!strcmp(command, "modify file")) {
    return 5;
  }
  else if (!strcmp(command, "restore file")) {
    return 10;
  }
  else if (!strcmp(command, "check diff")) {
    return 11;
  }
  else if (!strcmp(command, "list files")) {
    return 6;
  }
  else if (!strcmp(command, "list logs")) {
    return 7;
  }
  else if (!strcmp(command, "change user")) {
    return 8;
  }
  else if (!strcmp(command, "exit")) {
    return 9;
  }
  else if (!strcmp(command, "execute")) {
    return 12;
  }
  else if (!strcmp(command, "view content")) {
    return 13;
  }
  return 0;
}

void GUI::listStrings(list<string*> *listOfStrings) {
  GUI::clearScreen();
  std::list<string*>::iterator it=listOfStrings->begin();
  if (it == listOfStrings->end()) {
    cout << "Empty." << endl;
  }
  for (; it != listOfStrings->end(); ++it) {
    cout << (*it)->c_str() << endl;
  }
  GUI::pause();
}

void GUI::listLog(time_t *time, string *owner, string *log, int seq) {
  if (seq >= 0) {
    cout << "Version: " << seq << endl;
  }
  cout << asctime(localtime(time));
  cout << owner->c_str() << endl << endl;
  cout << log->c_str() << endl << endl;
}

void GUI::listLog(string *log) {
  cout << log->c_str();
}

void GUI::showLogged(string *_user) {
  GUI::clearScreen();
  cout << "Now you're logged as " + *_user << endl;
  GUI::pause();
}

void GUI::getDiff(string _choosen, string _previous) {
  GUI::clearScreen();
  string _diff;
  _diff += "diff ";
  _diff += _choosen;
  _diff += " ";
  _diff += _previous;
  system(_diff.c_str());
  GUI::pause();
}
