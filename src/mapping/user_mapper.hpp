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

  public:
    static list<User*> *loadUsers();
    static void saveUser(User *_user);
    static void deleteUser(string *_usrName);
};

#endif
