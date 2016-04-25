#ifndef _COMMON_USER_
#define _COMMON_USER_

class Commonuser;

#include <iostream>
#include <string>
#include "user.hpp"
#include "UI.hpp"

using namespace std;

class CommonUser : public User {
private:

public:
	CommonUser();
	CommonUser(const char *_name, const char *_pswd);
	CommonUser(string *_name, string *_pswd);
  
	virtual string *removeUser(UserManager *uM, string *_username);
	virtual string *removeFile(FileManager *fM, string *_filename);
  	virtual void addUser(UserManager *uM);
	virtual void addFile(FileManager *fM);
	virtual list<string*> *listFile(FileManager *fM);
};

#endif
