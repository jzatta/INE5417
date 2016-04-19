#include "commonUser.hpp"
#include <iostream>
#include <string>

using namespace std;

CommonUser::CommonUser(string _name, string _pswd) : User(_name, _pswd) {}

// constructor from the superclass
CommonUser::CommonUser() : User() {}

// common users doesn't have the ability to add another user
void CommonUser::addUser(User _user) {
	printf("permissão negada\n"); // remove, throw in vision
}
// common users doesn't have the ability to remove another user
void CommonUser::removeUser(User _user) {
	prinf("permissão negada\n"); // remove, throw in vision
}

void CommonUser::addFile(FILE file) {
  // what we gonna do with this method?
}

void CommmonUser::removeFile(/*??*/) {
  // ??
}

void CommonUser::listFile() {
  // the files will be organized in an atribute, a list or something?
}
