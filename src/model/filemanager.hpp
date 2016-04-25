#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

class FileManager;

#include "manager.hpp"
#include <iostream>
#include <string>
#include <list>
#include "File.hpp"

using namespace std;

class FileManager : public Manager {
  private:
    list<File*> *files;
  public:
    FileManager();
    FileManager(list<File*> *_files);
    bool exclude(void *fileName);
    void create(void *fileName);
};

#endif
