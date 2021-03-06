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
  int counter;
  list<Log*> *logs;

public:
  File(const char *_name);
  
  File(string *_name);

  File(string *_name, int counter);

  File(const char *_name, int counter);
  
  string *getName();

  int getCounter();

  void setName(string *_name);

  void setLogs(list<Log*> *_logs);

  string *fileLogVersion(int version);
  
  void modify();
  
  int restore(User *u, int version);

  void addLog(Log *log);

  list<string*> *listLogs();
  
  void save();
};

#endif
