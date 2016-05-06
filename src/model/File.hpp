#ifndef _FILE_
#define _FILE_

class File;

#include <iostream>
#include <string>
#include <list>
#include "Log.hpp"

using namespace std;

class File {
private:
  string *fileName;
  list<Log*> *logs;

public:
  File(const char *_name);
  
  File(string *_name);
  
  string *getName();

  void setName(string *_name);
  
  void modify();

  void addLog(Log *log);

  list<Log*> *listLogs();
  
  void save();
};

#endif
