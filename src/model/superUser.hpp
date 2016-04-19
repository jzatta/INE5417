#ifndef _SUPER_USER_
#define _SUPER_USER_

#pragma once

#include "user.hpp"
#include "usermanager.hpp"
#include <iostream>
#include <string>

using namespace std;

class SuperUser : public User {
  private:
    // ?
   public:
    SuperUser();
    SuperUser(string _name, string _pswd);

};

#endif
