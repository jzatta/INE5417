
#include "superUser.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "file_mapper.hpp"
#include "user_mapper.hpp"

using namespace std;

SuperUser::SuperUser(const char *_name, const char *_pswd) : User(_name, _pswd) {}
SuperUser::SuperUser(string *_name, string *_pswd) : User(_name, _pswd) {}

// constructor from the superclass
SuperUser::SuperUser() : User() {}

// common users doesn't have the ability to add another user
string *SuperUser::addUser(UserManager *uM, string *_name, string *_pswd, bool _super) {
  User *usr;
  if (_super) {
    usr = new SuperUser(_name, _pswd);
  } else {
    usr = new CommonUser(_name, _pswd);
  }
  // need to check if exists the user
  uM->create(usr);
  UserMapper::saveUser(usr);
  return new string("created");
}

// common users doesn't have the ability to remove another user
string *SuperUser::removeUser(UserManager *uM, string *_username) {
  string *verify = new string("don't exist");
  // need to check if exists the user
  if (uM->exclude(_username)) {
    delete verify;
    UserMapper::deleteUser(_username);
    verify = new string("removed");
  }
  return verify;
}

bool SuperUser::isSuper() {
  return true;
}

void SuperUser::addFile(FileManager *fM, string *_filename) {
  int checker = 0;
  File *_file = new File(_filename);
  list<File*> *listFiles = fM->getListFiles();
  list<File*>::iterator it = listFiles->begin();
  for(; it != listFiles->end(); ++it) {
    if(!strcmp((*it)->getName()->c_str(), _file->getName()->c_str())) {
      checker = 1;
    }
  }
  if(checker == 0) { 
    FileMapper::saveFile(_file);
    fM->create(new File(_filename));
  }
}

string *SuperUser::removeFile(FileManager *fM, string *_filename) {
  string *verify = new string("don't exist");
  if (fM->exclude(_filename)) {
    delete verify;
    FileMapper::deleteFile(_filename);
    verify = new string("removed");
  }
  return verify;
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
