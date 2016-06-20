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

  public:
    Connect();
    void connect_db();
};

#endif
