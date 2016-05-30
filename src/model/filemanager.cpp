
#include "filemanager.hpp"
#include <iostream>
#include <string>
#include <list>

FileManager::FileManager() {
  this->files = new list<File*>();
}

FileManager::FileManager(list<File*> *_files) {
  this->files = _files;
}

bool FileManager::exclude(string *fileName) {
  std::list<File*>::iterator it=files->begin();
  for (; it != files->end(); ++it) {
    if (!(*it)->getName()->compare(*fileName)) {
      files->erase(it);
      return true;
    }
  }
  return false;
}

void FileManager::create(void *file) {
  this->files->push_back((File*)file);
}

File *FileManager::getFile(string *fileName) {
  std::list<File*>::iterator it=files->begin();
  for (; it != files->end(); ++it) {
    if (!(*it)->getName()->compare(*fileName)) {
      return *it;
    }
  }
  return NULL;
}

list<File*> *FileManager::getListFiles() {
  // maybe return list of name of files
  return this->files;
}

void FileManager::save() {
  // must save in a file ".files.q"
}

list<Log*> *FileManager::listLogs(string *fileName) {
  File *file;
  file = this->getFile(fileName);
  if (file == NULL)
    return NULL;
  return file->listLogs();
}

int FileManager::restore(string *fileName, User *u, int version) {
  File *file;
  file = this->getFile(fileName);
  if (file == NULL)
    return NULL;
  return file->restore(u, version);
}


string *FileManager::fileLogVersion(string *fileName, int version) {
  File *file;
  file = this->getFile(fileName);
  if (file == NULL)
    return NULL;
  return file->fileLogVersion(version);
}
