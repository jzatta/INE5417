#include "user.hpp"
#include <iostream>
#include <string>

using namespace std;

User::User() {
	string name = "";
	string senha = "";
}

User::User(string _name, string _pswd) {
	this->name = _name;
	this->pswd = _pswd;
}

string User::getName() {
	return this->name;
}

string User::getPswd() {
	return this->pswd;
}

void User::setName(string _name) {
	this->name = _name;
}

void User::setPswd(string _pswd) {
	this->pswd = _pswd;
}

/*
  abstract methods, they will be implemented in the subclasses
*/

void addUser() {}

void removeUser() {}

void addFile() {}

void removeFile() {}

void listFile() {}
