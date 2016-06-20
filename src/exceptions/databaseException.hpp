#ifndef _DATABASE_EXCEPTION_
#define _DATABASE_EXCEPTION_

class DatabaseException;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

class DatabaseException {
  private:

  public:
    DatabaseException();
    // catch connections or query errors
    int badQuery(BadQuery er);
    // catch bad conversions
    int badConversion(const BadConversion &er);
    // catch all other mysql++ exceptions
    int exception(const Exception &er);
};

#endif
