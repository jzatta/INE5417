#ifndef _USER_MAPPER_
#define _USER_MAPPER_

class UserMapper;

#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"../model/user.hpp">

using namespace std;
using namespace mysqlpp;

class UserMapper {
  public:

  private:
    UserMapper();
    list<User> loadUsers();
    void saveUser(User *_user);
};

#endif
