
#include "usermanager.hpp"
#include <iostream>
#include <string>
#include "superUser.hpp"
#include "commonUser.hpp"

UserManager::UserManager() {
  this->users = new list<User*>();
  this->users->push_back(new SuperUser("root", "root"));
  this->users->push_back(new CommonUser("user", "user"));
}

UserManager::UserManager(list<User*> *_users) {
  this->users = _users;
}

bool UserManager::exclude(string *usr) {
  std::list<User*>::iterator it=users->begin();
  for (; it != users->end(); ++it) {
    if (!(*it)->getName()->compare(*usr)) {
      users->erase(it);
      return true;
    }
  }
  return false;
}

void UserManager::create(void *usr) {
  this->users->push_back((User*)usr);
}

User *UserManager::login(string *name, string *password) {
  std::list<User*>::iterator it=users->begin();
  for (; it != users->end(); ++it) {
    if (!(*it)->getName()->compare(*name)) {
      if ( (*it)->getAuth(password) ) {
        return *it;
      }
    }
  }
  return NULL;
}

void UserManager::save() {
  // must save in a file ".users.q"
}
