
#include "Log.hpp"
#include <time.h>
#include <iostream>
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
