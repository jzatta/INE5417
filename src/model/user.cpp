
#include "user.hpp"
#include <iostream>
#include <string>

using namespace std;

User::User() {
	this->name = new string();
	this->pswd = new string();
}

User::User(string *_name, string *_pswd) {
	this->name = _name;
	this->pswd = _pswd;
}

User::User(const char *_name, const char *_pswd) {
  this->name = new string(_name);
  this->pswd = new string(_pswd);
}

string *User::getName() {
	return this->name;
}

bool User::getAuth(string *_pswd) {
	if (this->pswd->compare(*_pswd)) {
    return false;
  }
  return true;
}

void User::setName(string *_name) {
  delete this->name;
	this->name = _name;
}

void User::setPswd(string *_pswd) {
  delete this->pswd;
	this->pswd = _pswd;
}

User::~User() {
  delete this->name;
  delete this->pswd;
}