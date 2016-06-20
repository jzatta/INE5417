#ifndef _FILE_MAPPER_
#define _FILE_MAPPER_

class FileMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"../model/File.hpp">

using namespace std;
using namespace mysqlpp;

class FileMapper {
  private:

  public:
    FileMapper();
    list<File> loadFiles();
    void saveFile(File *_file);
};

#endif
