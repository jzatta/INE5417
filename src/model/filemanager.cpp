
#include "File.hpp"
#include <iostream>
#include <string>
#include <list>

FileManager() {
  this->users = new list<File*>();
  this->users->push_back(new SuperUser("root", "root"));
}

FileManager(list<File*> *_files);
bool exclude(void *fileName);
void create(void *fileName);

#endif



UserManager::UserManager() {
  this->users = new list<User*>();
  this->users->push_back(new SuperUser("root", "root"));
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