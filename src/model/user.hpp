#ifndef _USER_
#define _USER_

class User;

#include <iostream>
#include <string>
#include "usermanager.hpp"
#include "filemanager.hpp"

using namespace std;

class User {
private:
	string *name;
	string *pswd;

public:
  User();
	User(const char *_name, const char *_pswd);
	User(string *_name, string *_pswd);
	/*
		getters and setters
	*/
	string *getName();
	bool getAuth(string *_pswd);
	void setName(string *_name);
	void setPswd(string *_pswd);

	/*
		non "getters and setters" stuff
	*/

	virtual string *removeUser(UserManager *uM, string *_username) = 0;
	virtual string *removeFile(FileManager *fM, string *_filename) = 0;
	virtual void addUser(UserManager *uM, string *_name, string *_pswd, bool _super) = 0;
	virtual void addFile(FileManager *fM, string *_filename) = 0;
	virtual list<string*> *listFile(FileManager *fM) = 0;
};

#endif
