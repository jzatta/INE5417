#include <iostream>
#include <stlib.h>
#include <mysql++.h>
#include <"../model/File.hpp">
#include <"../exceptions/databaseExceptions.hpp">
#include <list>
#include <"connect.hpp">

using namespace std;
using namespace mysqlpp;

FileMapper::FileMapper(Connect _conn) {
  this->conn = _conn->getConnection();
}

list<File> *FileMapper::loadFiles() {
  string *fileName;
  int counter;
  list<File*> *files = new list<File*>();
  try {
    Query query = this->conn.query();

    query << "SELECT * FROM file";
    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      *fileName = ares[i]["name"];
      counter = ares[i]["counter"];
      files->push_back(new File(fileName, counter));
    }
  } catch(BadQuery er) {
    
    return DatabaseException::badQuery(er);

  } catch(const BadConversion &er) {
    
    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {
    
    return DatabaseException::exception(er);

  }

  return files;
}

void FileMapper::saveFile(File *_file) {
  try {
    Query query = this->conn.query();

    query << "INSERT INTO file" << "VALUES ("
          << _file->getName() << ", " << _file->getCounter() 
          << "\"" << ");";
    query.execute();
  } catch(BadQuery er) {

    return DatabaseException::badQuery(er);

  } catch(const BadConversion &er) {

    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {

    return DatabaseException::exception(er);
  
  }
}
