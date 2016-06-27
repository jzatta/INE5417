#ifndef _CONNECT_
#define _CONNECT_

class Connect;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

class Connect {
  private:
    static Connection *conn;
    static void connect_db();
  public:
    static Connection *getConnection();
};

#endif
