#ifndef _FILE_
#define _FILE_

class File;

#include <iostream>
#include <string>
#include "Log.hpp"

using namespace std;

class File {
private:
	string *name;
  list<Log*> *log;

public:
	File(const char *_name);
	File(string *_name);
  
	string *getName();
	void setName(string *_name);

	void addLog(Log *log);
	list<Log*> *listLog();
};

#endif
