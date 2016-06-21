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
    Connection *conn;

  public:
    Connection *getConnection();
    Connect();
    void connect_db();
};

#endif
