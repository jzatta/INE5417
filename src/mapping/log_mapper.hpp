#ifndef _LOG_MAPPER_
#define _LOG_MAPPER_

class LogMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"connect.hpp">
#include <"../model/Log.hpp">
#include <"../model/user.hpp">
#include <"../model/File.hpp">

using namespace std;
using namespace mysqlpp;

class LogMapper {
  private:
    Connection conn(false);

  public:
    LogMapper();
    LogMapper(Connect _conn);
    list<Log> *loadLogs(File *_file);
    void saveLog(Log *_log, string *_fname);
};

#endif
