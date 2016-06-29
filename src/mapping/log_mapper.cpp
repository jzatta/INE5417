
#include "log_mapper.hpp"

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include "connect.hpp"
#include "Log.hpp"
#include "File.hpp"
#include "databaseException.hpp"

LogMapper::LogMapper() {
  this->conn = Connect::getConnection();
}

// load logs list to each file
list<Log*> *LogMapper::loadLogs(File *_file) {
  string *change;
  string *owner;
  time_t *date;
  int sequence;

  string *_name = _file->getName();
  list<Log*> *logs = new list<Log*>();
  try {
    Query query = this->conn->query();

    query << "SELECT * FROM log WHERE file = `"
          << *_name << "`";

    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      change = new string(ares[i]["change"]);
      owner = new string(ares[i]["owner"]);
      date = new long int(atol(ares[i]["date"]));
      sequence = atoi(ares[i][sequence]);
      logs->push_back(new Log(change, owner, date, sequence));
    }
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
  return logs;
}

void LogMapper::saveLog(Log *_log, string *_fname) {
  try {
    Query query = this->conn->query();

    query << "INSERT INTO `log`(`change`,`owner`,`data`,`sequence`,`name`) VALUES ('"
          << _log->getChange()->c_str() << "', '"
          << _log->getOwner()->c_str() << "', "
          << _log->getTime() << ", "
          << _log->getSequence() << ", '"
          << _fname->c_str() << "'" << ");";
    
          
    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}
