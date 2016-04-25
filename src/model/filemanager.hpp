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
  bool exclude(string *fileName);
  void create(void *file);
  File *getFile(string *fileName);
  list<File*> *getListFiles();
  virtual void save();
};

#endif
