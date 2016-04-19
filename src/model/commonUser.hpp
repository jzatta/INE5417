#ifndef _COMMON_USER_
#define _COMMON_USER_

#include "user.hpp"
#include <iostream>
#include <string>

using namespace std;

class CommonUser : public User {
private:

public:
	CommonUser();
	CommonUser(string _name, string _pswd);

};

#endif