#ifndef _Control_
#define _Control_

#pragma once

class Control;

#include <iostream>
#include <string>
#include "user.hpp"
#include "superUser.hpp"
#include "usermanager.hpp"

using namespace std;

class Control {
private:
  UserManager *uM;
  FileManager *fM;
  User *logged;
public:
  Control();

  void run();
  void login();
  
  void restore();
  void diff();
};

#endif
