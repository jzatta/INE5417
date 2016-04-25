#ifndef _UI_
#define _UI_

#pragma once

class UI;

#include <iostream>
#include <string>
#include "user.hpp"
#include "superUser.hpp"
#include "usermanager.hpp"

using namespace std;

class UI {
private:
  UserManager *uM;
  FileManager *fM;
  User *logged;
public:
  UI();

  void run();
  void login();
  static void clearScreen();
  static void pause();
};

#endif
