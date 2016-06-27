#include "connect.hpp"
#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include "databaseException.hpp"

using namespace std;
using namespace mysqlpp;

Connection *Connect::conn = NULL;

void Connect::connect_db() {
  try {
    conn = new Connection(false);
    conn->connect("root", "localhost", "root", "root");
  } catch (BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch (const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch (const Exception &er) {
    throw DatabaseException::exception(er);
  }

  //return(EXIT_SUCCESS);
}

Connection *Connect::getConnection() {
  if (Connect::conn == NULL) {
    Connect::connect_db();
  }
  return conn;
}
