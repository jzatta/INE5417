
#include "commonUser.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include "file_mapper.hpp"

using namespace std;

CommonUser::CommonUser(const char *_name, const char *_pswd) : User(_name, _pswd) {}
CommonUser::CommonUser(string *_name, string *_pswd) : User(_name, _pswd) {}

// constructor from the superclass
CommonUser::CommonUser() : User() {}

// common users doesn't have the ability to add another user
string *CommonUser::addUser(UserManager *uM, string *_name, string *_pswd, bool _super) {
  // in control, verify instance type and throw vision exception.
  return new string("access denied");
}
// common users doesn't have the ability to remove another user
string *CommonUser::removeUser(UserManager *uM, string *_username) {
  // the same thing that the above one
  return new string("access denied");
}

void CommonUser::addFile(FileManager *fM, string *_fname) {
  // need to check if exists the file
  int checker = 0;
  File *_file = new File(_fname);
  list<File*> *listFiles = fM->getListFiles();
  list<File*>::iterator it = listFiles->begin();
  for(; it != listFiles->end(); ++it) {
    if(strcmp((*it)->getName()->c_str(), _file->getName()->c_str())) {
      checker = 1;
    }
  }
  if(checker == 0) { 
    FileMapper::saveFile(_file);
    fM->create(new File(_fname));
  }
}

bool CommonUser::isSuper() {
  return false;
}

string *CommonUser::removeFile(FileManager *fM, string *_filename) {
  string *verify = new string("don't exist");
  if (fM->exclude(_filename)) {
    delete verify;
    FileMapper::deleteFile(_filename);
    verify = new string("removed");
  }
  return verify;
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
