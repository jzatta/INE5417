#ifndef _USER_MANAGER_
#define _USER_MANAGER_

class UserManager;

#include <iostream>
#include <string>
#include <list>
#include "manager.hpp"
#include "user.hpp"

using namespace std;

class UserManager : public Manager {
  private:
    list<User*> *users;
  public:
    UserManager();
    UserManager(list<User*> *_users);
    User *login(string *name, string *password);
    bool exclude(string *usr);
    void create(void *usr);
    void save();
};

#endif
