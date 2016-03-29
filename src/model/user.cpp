#include "user.hpp"
#include <iostream>
#include <string>

using namespace std;

User::User() {
	string name = "";
	string senha = "";
}

User::User(string name, string pswd) {
	this->name = name;
	this->pswd = pswd;
}

string User::getName() {
	return this->name;
}

string User::getPswd() {
	return this->pswd;
}

void User::setName(string name) {
	this->name = name;
}

void User::setPswd(string pswd) {
	this->pswd = pswd;
}