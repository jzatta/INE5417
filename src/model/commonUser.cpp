
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
  UI::pause();
}
// common users doesn't have the ability to remove another user
void CommonUser::removeUser(UserManager *uM) {
	cout << "access denied" << endl; // remove, throw in vision
  UI::pause();
}

void CommonUser::addFile(FileManager *fM) {
  char name[100];
  
  UI::clearScreen();
  cout << "Insert file name" << endl;
  cin.getline(name, sizeof(name));
  // need to check if exists the file
  fM->create(new File(name));
  
  cout << "File created" << endl;
  UI::pause();
}

void CommonUser::removeFile(FileManager *fM) {
  // ??
}

list<string*> *CommonUser::listFile(FileManager *fM) {
  list<string*> *listFilesName = new list<string*>;
  list<File*> *listFiles = fM->getListFiles();
  list<File*>::iterator it=listFiles->begin();
  for (; it != listFiles->end(); ++it) {
    listFilesName->push_back((*it)->getName());
  }
  return listFilesName;
}
