
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
  this->counter = 0;
}

File::File(string *_name) {
  this->fileName = _name;
  this->logs = new list<Log*>();
  this->counter = 0;
}

string *File::getName() {
  return fileName;
}

void File::setName(string *_name) {
  // need to move file inside here, not necessary
  return;
}

void File::modify() {
  string cpyCommand, cpy("cp -p ");
  char tmp[10];
  sprintf(tmp, ".%d", (this->counter)++);
  cpyCommand = cpy + *(this->fileName) + " ." + *(this->fileName) + tmp;
  system(cpyCommand.c_str());
  string nanoCommand, nano("nano ");
  nanoCommand = nano + *(this->fileName);
  system(nanoCommand.c_str());
}

int File::restore(User *u, int version) {
  if (version < 0 || version >= this->counter) {
    return -1;
  }
  string cpyCommand, cpy("cp -p ");
  char tmp[30];
  sprintf(tmp, ".%d", (this->counter)++);
  cpyCommand = cpy + *(this->fileName) + " ." + *(this->fileName) + tmp;
  system(cpyCommand.c_str());
  sprintf(tmp, ".%d ", version);
  cpyCommand = cpy + " ." + *(this->fileName) + tmp + *(this->fileName);
  system(cpyCommand.c_str());
  sprintf(tmp, "Version %d restored", version);
  this->addLog(new Log(tmp, u));
  return 0;
}

string *File::fileLogVersion(int version) {
  if(version < 0 || version > this->counter) {
    return NULL;
  }
  string *_logVersion = new string();
  char tmp[30];
  if(version == this->counter) {
    return this->fileName;   
  }
  sprintf(tmp, ".%d ", version);
  *_logVersion += ".";
  *_logVersion += *(this->fileName);
  *_logVersion += tmp;
  return _logVersion;
}

void File::addLog(Log *log) {
  log->setSequence(this->counter);
  this->logs->push_back(log);
}

list<string*> *File::listLogs() {
  // maybe return a list of strings
#if 1
  time_t *time;
  string *owner;
  string *log;
  int seq;
  std::list<string*> *logsString = new std::list<string*>();
  std::list<Log*>::iterator itLog;
  string tmpStr = "Version: ";
  itLog = this->logs->begin();
  for (; itLog != this->logs->end(); ++itLog) {
    seq = (*itLog)->getSequence();
    time = (*itLog)->getTime();
    owner = (*itLog)->getOwner();
    log = (*itLog)->getChange();
    if (seq >= 0) {
      tmpStr = tmpStr + to_string(seq) + "\n";
    }
    tmpStr = tmpStr + asctime(localtime(time));
    tmpStr = tmpStr + *owner + "\n\n";
    tmpStr = tmpStr + *log + "\n\n";
    logsString->push_back(new string(tmpStr));
  }
  return logsString;
#else
  return logs;
#endif
}
