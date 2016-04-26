
#include "File.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Log.hpp"

using namespace std;

File::File(const char *_name) {
  this->fileName = new string(_name);
  this->logs = new list<Log*>();
}

File::File(string *_name) {
  this->fileName = _name;
  this->logs = new list<Log*>();
}

string *File::getName() {
  return fileName;
}

void File::setName(string *_name) {
  // need to move file inside here, not necessary
  return;
}

void File::modify() {
  string nanoCommand, nano("nano ");
  nanoCommand = nano + *(this->fileName);
  system(nanoCommand.c_str());
}

void File::addLog(Log *log) {
  this->logs->push_back(log);
}

list<Log*> *File::listLogs() {
  // maybe return a list of strings
  return logs;
}