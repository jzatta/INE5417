#pragma once

#include "usermanager.hpp"
#include <iostream>
#include <string>

using namespace std

UserManager::UserManager() {
  this->users.empty();
}

UserManager::UserManager(list<User> _users) {
  this->users = _users;
}

void UserManager::exclude(User usr) {
  this->users.remove_if(usr);
}

void UserManager::create(User usr) {
  this->users.insert(usr);
}
