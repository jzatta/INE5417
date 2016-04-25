
#include "commonUser.hpp"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

CommonUser::CommonUser(const char *_name, const char *_pswd) : User(_name, _pswd) {}
CommonUser::CommonUser(string *_name, string *_pswd) : User(_name, _pswd) {}

// constructor from the superclass
CommonUser::CommonUser() : User() {}

// common users doesn't have the ability to add another user
void CommonUser::addUser(UserManager *uM) {
	cout << "access denied" << endl; // remove, throw in vision
  fgetc(stdin); // pause
}
// common users doesn't have the ability to remove another user
void CommonUser::removeUser(UserManager *uM) {
	cout << "access denied" << endl; // remove, throw in vision
  fgetc(stdin); // pause
}

void CommonUser::addFile(FileManager *uF) {
  // what we gonna do with this method?
}

void CommonUser::removeFile(FileManager *uF) {
  // ??
}

void CommonUser::listFile(FileManager *uF) {
  // the files will be organized in an atribute, a list or something?
}
