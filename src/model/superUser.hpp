#ifndef _SUPER_USER_
#define _SUPER_USER_

class SuperUser;

#include <iostream>
#include <string>
#include "user.hpp"
#include "usermanager.hpp"
#include "filemanager.hpp"
#include "commonUser.hpp"
#include "UI.hpp"

using namespace std;

class SuperUser : public User {
private:
  // ?
public:
  	SuperUser();
  	SuperUser(const char *_name, const char *_pswd);
  	SuperUser(string *_name, string *_pswd);
  	virtual void addUser(UserManager *uM)    ;
	virtual void removeUser(UserManager *uM) ;
	virtual void addFile(FileManager *fM)    ;
	virtual void removeFile(FileManager *fM) ;
	virtual list<string*> *listFile(FileManager *fM)   ;
};

#endif
