
#include "superUser.hpp"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

SuperUser::SuperUser(const char *_name, const char *_pswd) : User(_name, _pswd) {}
SuperUser::SuperUser(string *_name, string *_pswd) : User(_name, _pswd) {}

// constructor from the superclass
SuperUser::SuperUser() : User() {}

// common users doesn't have the ability to add another user
void SuperUser::addUser(UserManager *uM) {
  char name[100], password[100];
  bool super;
  User *usr;
  
  cout << "\033[H\033[2J" << endl;
  cout << "Insert user name" << endl;
  cin.getline(name, sizeof(name));
  cout << "Insert password" << endl;
  cin.getline(password, sizeof(password));
  cout << "Is superuser" << endl;
  cin >> super;
  
  if (super) {
    usr = new SuperUser(name, password);
  } else {
    usr = new CommonUser(name, password);
  }
  // need to check if exists the user
  uM->create(usr);
  
  cout << "User created" << endl;
  fgetc(stdin); // pause
}

// common users doesn't have the ability to remove another user
void SuperUser::removeUser(UserManager *uM) {
  char name[100];
  string *sName;
  
  cout << "\033[H\033[2J" << endl;
  cout << "Insert user name" << endl;
  cin.getline(name, sizeof(name));
  
  sName = new string(name);
  // need to check if exists the user
  uM->exclude(sName);
  
  cout << "User created" << endl;
  fgetc(stdin); // pause
}

void SuperUser::addFile(FileManager *uF) {
  // what we gonna do with this method?
}

void SuperUser::removeFile(FileManager *uF) {
  // ??
}

void SuperUser::listFile(FileManager *uF) {
  // the files will be organized in an atribute, a list or something?
}
