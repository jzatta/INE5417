#include "connect.hpp"
#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include "databaseException.hpp"

using namespace std;
using namespace mysqlpp;

Connect::Connect() {
  connect_db();
}

void Connect::connect_db() {
  try {
    this->conn->connect("root", "localhost", "root", "root");
    Query query = conn->query();
  } catch (BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch (const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch (const Exception &er) {
    throw DatabaseException::exception(er);
  }

  //return(EXIT_SUCCESS);
}
