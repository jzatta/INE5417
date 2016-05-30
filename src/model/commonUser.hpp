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
  
	virtual string *removeUser(UserManager *uM, string *_username);
	virtual string *removeFile(FileManager *fM, string *_filename);
  virtual string *addUser(UserManager *uM, string *_name, string *_pswd, bool _super);
	virtual void addFile(FileManager *fM, string *_filename);
	virtual list<string*> *listFile(FileManager *fM);
};

#endif
