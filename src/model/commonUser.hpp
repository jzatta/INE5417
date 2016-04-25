#ifndef _COMMON_USER_
#define _COMMON_USER_

class Commonuser;

#include <iostream>
#include <string>
#include "user.hpp"

using namespace std;

class CommonUser : public User {
private:

public:
	CommonUser();
	CommonUser(const char *_name, const char *_pswd);
	CommonUser(string *_name, string *_pswd);
  
  virtual void addUser(UserManager *uM);
	virtual void removeUser(UserManager *uM);
	virtual void addFile(FileManager *uF);
	virtual void removeFile(FileManager *uF);
	virtual void listFile(FileManager *uF);
};

#endif
