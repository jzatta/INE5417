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
    // catch connections or query errors
    static int badQuery(BadQuery er);
    // catch bad conversions
    static int badConversion(const BadConversion &er);
    // catch all other mysql++ exceptions
    static int exception(const Exception &er);
};

#endif
