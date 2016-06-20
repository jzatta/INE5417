#ifndef _CONNECT_
#define _CONNECT_

class Connect;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

class File {
  private:
    Connection conn(false);

  public:
    Connection getConnection();
    Connect();
    void connect_db();
};

#endif
