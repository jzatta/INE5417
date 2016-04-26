
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
  	cout << "File " << _param << "d" << endl;
  	GUI::pause();
  	return new string(name);
}

string *GUI::getUserName(const char *_param) {
	char name[100];
  	GUI::clearScreen();
  	cout << "Insert user name to " << _param << endl;
  	cin.getline(name, sizeof(name));
  	GUI::pause();
  	return new string(name);
}

string *GUI::getUserPswd() {
	char password[100];
	GUI::clearScreen();
	cout << "Insert password" << endl;
  cin.getline(password, sizeof(password));
  GUI::pause();
  return new string(password);
}

bool GUI::getUserResp() {
	char super[5];
	GUI::clearScreen();
	cout << "Is superuser (yes/no)" << endl;
  cin.getline(super, sizeof(super));
  GUI::pause();
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

void GUI::clearScreen() {
  cout << "\033[H\033[2J" << endl;
  return;
}

void GUI::pause() {
  fgetc(stdin); // pause
  return;
}
