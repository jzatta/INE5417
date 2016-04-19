#ifndef _MANAGER_
#define _MANAGER_

#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
  A generic class that could be expecialized in file or user manager, 
  this class will have abstract methods that will be implemented in the subclasses
 */

class Manager {
  private:

  public:
    Manager();
    void exclude();
    void create();
};

#endif
