#ifndef _FILE_MAPPER_
#define _FILE_MAPPER_

class FileMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include "File.hpp"
#include "connect.hpp"

using namespace std;
using namespace mysqlpp;

class FileMapper {
  private:
    Connection conn(false);

  public:
    FileMapper();
    FileMapper(Connect _conn);
    list<File> *loadFiles();
    void saveFile(File *_file);
};

#endif
