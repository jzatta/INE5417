#ifndef _SUPER_USER_
#define _SUPER_USER_

class SuperUser;

#include <iostream>
#include <string>
#include "user.hpp"
#include "usermanager.hpp"
#include "filemanager.hpp"
#include "commonUser.hpp"

using namespace std;

class SuperUser : public User {
private:
  // ?
public:
  SuperUser();
  SuperUser(const char *_name, const char *_pswd);
  SuperUser(string *_name, string *_pswd);
  virtual bool isSuper();
	virtual string *removeUser(UserManager *uM, string *_username) ;
  virtual string *addUser(UserManager *uM, string *_name, string *_pswd, bool _super);
	virtual string *removeFile(FileManager *fM, string *_filename) ;
	virtual void addFile(FileManager *fM, string *_filename)    ;
	virtual list<string*> *listFile(FileManager *fM)   ;
};

#endif
