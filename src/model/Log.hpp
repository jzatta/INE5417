#ifndef _LOG_
#define _LOG_

class Log;

#include <iostream>
#include <string>
#include <stdio.h>
#include "user.hpp"

using namespace std;

class Log {
private:
  string *change;
  string *owner;
  time_t *date;
  int sequence;
  string *fname;
  
public:
  Log(const char *change, User *owner);
  Log(string *change, User *owner);
  Log(string *change, User *owner, string *fname);
  // created to load logs from db
  Log(string *change, string *owner, time_t *date, int sequence);
  void saveLog(string *_logname);
  /*
   *    getters and setters
   */
  time_t *getTime();
  string *getChange();
  string *getOwner();
  int getSequence();
  void setSequence(int _sequence);
  void setChange(string *_change);
};

#endif
