  
#include "Log.hpp"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <malloc.h>

using namespace std;

Log::Log(const char *_change, User *_owner) {
  this->change = new string(_change);
  this->owner = _owner->getName();
  this->date = (time_t *)malloc(sizeof(time_t));
  time(this->date);
}

Log::Log(string *_change, User *_owner) {
  this->change = _change;
  this->owner = _owner->getName();
  this->date = (time_t *)malloc(sizeof(time_t));
  time(this->date);
}

void *Log::saveLog(string *_logname) {
  ofstream myFile;
  myFile.open(_logname->c_str());
  myFile << this->getOwner();
  myFile << (string*)this->getTime();
  myFile << this->getChange();
  myFile.close();
}

time_t *Log::getTime() {
  return this->date;
}

string *Log::getChange() {
  return this->change;
}

string *Log::getOwner() {
  return this->owner;
}

void Log::setChange(string *_change) {
  this->change = _change;
}