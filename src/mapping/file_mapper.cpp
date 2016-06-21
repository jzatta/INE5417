
#include "file_mapper.hpp"

#include <iostream>
#include <mysql++.h>
#include <list>
#include "File.hpp"
#include "databaseException.hpp"
#include "connect.hpp"

using namespace std;
using namespace mysqlpp;

FileMapper::FileMapper(Connect *_conn) {
  this->conn = _conn->getConnection();
}

list<File*> *FileMapper::loadFiles() {
  string *fileName;
  int counter;
  list<File*> *files = new list<File*>();
  try {
    Query query = this->conn->query();

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
    Query query = this->conn->query();

    query << "INSERT INTO file" << "VALUES ("
          << _file->getName() << ", " << _file->getCounter() 
          << "\"" << ");";
    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}
