
#include "file_mapper.hpp"

#include <iostream>
#include <mysql++.h>
#include <list>
#include "File.hpp"
#include "databaseException.hpp"
#include "connect.hpp"

using namespace std;
using namespace mysqlpp;

list<File*> *FileMapper::loadFiles() {
  string *fileName;
  int counter;
  list<File*> *files = new list<File*>();
  try {
    Query query = Connect::getConnection()->query();

    query << "SELECT * FROM file";
    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      fileName = new string(ares[i]["name"]);
      counter = atoi(ares[i]["counter"]);
      files->push_back(new File(fileName, counter));
    }
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }

  return files;
}

void FileMapper::saveFile(File *_file) {
  try {
    Query query = Connect::getConnection()->query();

    query << "INSERT INTO `file`" << "VALUES ('"
          << _file->getName()->c_str() << "', " << _file->getCounter()
          << "" << ");";
    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}

void FileMapper::deleteFile(string *_fname) {
  try {
    Query query = Connect::getConnection()->query();

    query << "DELETE FROM file " << "WHERE name = '"
          << *_fname << "'";

    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}

void FileMapper::updateFile(File *_file) {
  string *_fname = _file->getName();
  try {
    Query query = Connect::getConnection()->query();

    query << "UPDATE file SET name = " << _fname
          << "counter = " << _file->getCounter()
          << "WHERE name = '" << _fname << "'";

    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}
