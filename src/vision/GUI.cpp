
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GUI.hpp"
#include "UI.hpp"

using namespace std;

void GUI::permissionException() {
	GUI::clearScreen();
	cout << "acess denied" << endl;
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
	char password[100];
	GUI::clearScreen();
	cout << "Insert password" << endl;
  cin.getline(password, sizeof(password));
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

void GUI::deleteNotification(string *_type, string *_verify) {
	GUI::clearScreen();
    cout << *_type + " " + *_verify << endl;
    GUI::pause();
}

void GUI::fileDontExist() {
  cout << "File dont exist." << endl;
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
  char passwd[100];
  GUI::clearScreen();
  cout << "Password" << endl;
  cin.getline(passwd, sizeof(passwd));
  
  return new string(passwd);
}

string *GUI::getChanges() {
  char change[250];
  GUI::clearScreen();
  cout << "Tell me what changes you do" << endl;
  cin.getline(change, sizeof(change));
  return new string(change);
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
  cout << "list files" << endl;
  cout << "list logs" << endl;
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
  else if (!strcmp(command, "list files")) {
    return 6;
  }
  else if (!strcmp(command, "list logs")) {
    return 7;
  }
  else if (!strcmp(command, "exit")) {
    return 8;
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

void GUI::listLog(time_t *time, string *owner, string *log) {
  cout << asctime(localtime(time)) << endl;
  cout << owner->c_str() << endl;
  cout << log->c_str() << endl << endl;
}

