#ifndef _USER_
#define _USER_

#pragma once

#include <iostream>
#include <string>

using namespace std;

class User {
private:
	string name;
	string pswd;

public:
	User();
	User(string _name, string _pswd);
	/*
		getters and setters
	*/
	string getName();
	string getPswd();
	void setName(string _name);
	void setPswd(string _pswd);

	/*
		non "getters and setters" stuff
	*/

	void addUser();
	void removeUser();
	void addFile();
	void removeFile();
	void listFile();
	// maybe a search file method
};

#endif
