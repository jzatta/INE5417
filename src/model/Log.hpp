#ifndef _LOG_
#define _LOG_

class Log;

#include <iostream>
#include <string>
#include "user.hpp"

using namespace std;

class Log {
private:
  string *change;
  string *owner;
	time_t *date;

public:
	Log(const char *change, User *owner);
	Log(string *change, User *owner);
	/*
		getters and setters
	*/
	time_t *getTime();
	string *getChange();
  string *getOwner();
	void setChange(string *_chenge);
};

#endif
