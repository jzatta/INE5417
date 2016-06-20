#ifndef _LOG_MAPPER_
#define _LOG_MAPPER_

class LogMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"../model/Log.hpp">
#include <"../model/user.hpp">
#include <"../model/File.hpp">

using namespace std;
using namespace mysqlpp;

class LogMapper {
  public:

  private:
    LogMapper();
    list<Log> loadLogs(File *_file);
    void saveLog(Log *_log);
};

#endif
