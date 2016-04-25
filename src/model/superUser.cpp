
#include "superUser.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

SuperUser::SuperUser(const char *_name, const char *_pswd) : User(_name, _pswd) {}
SuperUser::SuperUser(string *_name, string *_pswd) : User(_name, _pswd) {}

// constructor from the superclass
SuperUser::SuperUser() : User() {}

// common users doesn't have the ability to add another user
void SuperUser::addUser(UserManager *uM) {
  char name[100], password[100];
  char super[5];
  User *usr;
  
  UI::clearScreen();
  cout << "Insert user name" << endl;
  cin.getline(name, sizeof(name));
  cout << "Insert password" << endl;
  cin.getline(password, sizeof(password));
  cout << "Is superuser (yes/no)" << endl;
  cin.getline(super, sizeof(super));
  if (!strcmp(super, "yes")) {
    usr = new SuperUser(name, password);
  } else {
    usr = new CommonUser(name, password);
  }
  
  // need to check if exists the user
  uM->create(usr);
  
  cout << "User created" << endl;
  UI::pause();
}

// common users doesn't have the ability to remove another user
void SuperUser::removeUser(UserManager *uM) {
  char name[100];
  string *sName;
  
  UI::clearScreen();
  cout << "Insert user name" << endl;
  cin.getline(name, sizeof(name));
  
  sName = new string(name);
  // need to check if exists the user
  if (uM->exclude(sName)) {
    cout << "User removed" << endl;
  } else {
    cout << "User dont exist." << endl;
  }
  
  UI::pause();
}

void SuperUser::addFile(FileManager *fM) {
  char name[100];
  
  UI::clearScreen();
  cout << "Insert new file name" << endl;
  cin.getline(name, sizeof(name));
  // need to check if exists the file
  fM->create(new File(name));
  
  cout << "File created" << endl;
  UI::pause();
}

void SuperUser::removeFile(FileManager *fM) {
  char name[100];
  string *sName;
  
  UI::clearScreen();
  cout << "Insert file name to remove" << endl;
  cin.getline(name, sizeof(name));
  
  sName = new string(name);
  // need to check if exists the user
  UI::clearScreen();
  if (fM->exclude(sName)) {
    cout << "File removed" << endl;
  } else {
    cout << "File dont exist." << endl;
  }
  
  UI::pause();
}

list<string*> *SuperUser::listFile(FileManager *fM) {
  list<string*> *listFilesName = new list<string*>;
  list<File*> *listFiles = fM->getListFiles();
  list<File*>::iterator it=listFiles->begin();
  for (; it != listFiles->end(); ++it) {
    listFilesName->push_back((*it)->getName());
  }
  return listFilesName;
}
