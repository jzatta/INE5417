#include <iostream>
#include <string>
#include "GUI.hpp"
#include "UI.hpp"

using namespace std;

void permissionException() {
	UI::clearScreen();
	cout << "acess denied" << endl;
	UI::pause();
}

string *fileName(const string _param) {
	char name[100];
  	UI::clearScreen();
  	cout << "Insert file name "+param << endl;
  	cin.getline(name, sizeof(name));  
  	cout << "File created" << endl;
  	UI::pause();
  	return new string(name);
}

string *userName(const string _param) {
	char name[100];
  	UI::clearScreen();
  	cout << "Insert user name "+param << endl;
  	cin.getline(name, sizeof(name));
  	UI:pause();
  	return new string(name);
}

string *userPswd() {
	char password[100];
	UI::clearScreen();
	cout << "Insert password" << endl;
  	cin.getline(password, sizeof(password));
  	UI:pause();
  	return new string(password);
}

string *userResp() {
	char super[5];
	UI::clearScreen();
	cout << "Is superuser (yes/no)" << endl;
  	cin.getline(super, sizeof(super));
  	UI::pause();
  	return new string(super);
}

void userCreated() {
	UI::clearScreen();
	cout << "User created" << endl;
  	UI::pause();
}

void fileCreated() {
	UI::clearScreen();
	cout << "File created" << endl;
	UI::pause();
}

void deleteNotification(const string _type, string *_verify) {
	UI::clearScreen();
    cout << _type+" "+_verify << endl;
    UI::pause();
}