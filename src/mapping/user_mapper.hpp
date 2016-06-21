#ifndef _USER_MAPPER_
#define _USER_MAPPER_

class UserMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include "user.hpp"
#include "connect.hpp"

using namespace std;
using namespace mysqlpp;

class UserMapper {
  private:
    Connection *conn;

  public:
    UserMapper();
    UserMapper(Connect *_conn);
    list<User*> *loadUsers();
    void saveUser(User *_user);
};

#endif
