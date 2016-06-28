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

  public:
    static list<File*> *loadFiles();
    static void saveFile(File *_file);
    static void deleteFile(string *_fname);
    static void updateFile(File *_file);
};

#endif
