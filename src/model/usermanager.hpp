#ifndef _USER_MANAGER_
#define _USER_MANAGER_

#pragma once

#include "manager.hpp"
#include <iostream>
#include <string>

using namespace std;

class UserManager : public Manager {
  private;
    User* users;
  public:
    Manager(User* _users);
    void exclude(User usr);
    void create(User usr);
};

#endif
