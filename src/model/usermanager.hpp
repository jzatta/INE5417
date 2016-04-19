#ifndef _USER_MANAGER_
#define _USER_MANAGER_

#pragma once

#include "manager.hpp"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class UserManager : public Manager {
  private:
    list<User> users;
  public:
    UserManager();
    UserManager(list<User> _users);
    void exclude(User usr);
    void create(User usr);
};

#endif
