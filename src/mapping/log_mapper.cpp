#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"connect.hpp">
#include <"../model/Log.hpp">
#include <"../model/File.hpp">

LogMapper(Connect _conn) {
  this->conn = _conn->getConnection();
}

// load logs list to each file
list<Log> *LogMapper::loadLogs(File *_file) {
  string *change;
  string *owner;
  time_t *date;
  int sequence;

  *_name = _file->getName();
  list<Log*> *logs = new list<Log*>();
  try {
    Query query = this->conn.query();

    query << "SELECT * FROM log WHERE file = "
          << *_name;

    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      *change = ares[i]["change"];
      *owner = ares[i]["owner"];
      *date = ares[i]["date"];
      sequence = ares[i][sequence];
      logs->push_back(new Log(change, owner, date, sequence);
    }
  } catch(BadQuery er) {
    
    return DatabaseException::badQuery(er);

  } catch(const BadConversion &er) {

    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {

    return DatabaseException::exception(er);

  }
  return logs;
}

void LogMapper::saveLog(Log *_log, string *_fname) {
  try {
    Query query = this->conn.query();

    query << "INSERT INTO log" << "VALUES ("
          << _log->getChange() << ", " 
          << _log->getOwner() << ", " 
          << _log->getTime() << ", " 
          << _log->getSequence() << ", "
          << _fname << "\"" << ");";
    
    query.execute();
  } catch(BadQuery er) {

    return DatabaseException::badQuery(er);

  } catch(const BadConversion &er) {

    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {

    return DatabaseException::exception(er);

  }
}

