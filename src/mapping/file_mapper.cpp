#include <iostream>
#include <stlib.h>
#include <mysql++.h>
#include <"../model/File.hpp">
#include <"../exceptions/databaseExceptions.hpp">
#include <list>

using namespace std;
using namespace mysqlpp;

list<File> FileMapper::loadFiles() {
  string *fileName;
  int counter;
  list<File*> files = new list<File*>();
  try {
    Connection conn(false);
    // DB NAME, DB HOST, DB USER, DB PASSWORD
    conn.connect("root", "localhost", "root", "root");
    Query query = conn.query();

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
    Connection conn(false);
    conn.connect("root", "localhost", "root", "root");
    Query query = conn.query();

    query << "INSERT INTO file" << "VALUES ("
          << file->getName() << getCounter() << "\""
          << ");";
    query.execute();
  } catch(BadQuery er) {

    return DatabaseException::badQuery(er);

  } catch(const BadConversion &er) {

    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {

    return DatabaseException::exception(er);
  
  }
}
