// C/C++ includes
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <mysql++.h>

// other classes includes
#include "user.hpp"
#include "superUser.hpp"
#include "commonUser.hpp"
#include <"user_mapper.hpp">
#include "connect.hpp"
#include "databaseException.hpp"

using namespace std;
using namespace mysqlpp;

UserMapper::UserMapper(Connect _conn) {
  this->conn = _conn->getConnection();
}

list<User*> *UserMapper::loadUsers() {
  string *_name;
  string *_pswd;
  string *_auth;
  list<User*> *users = new list<User*>();
  try {
    Query query = this->conn.query();

    query << "SELECT * FROM user";
    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      *_name = ares[i]["name"];
      *_pswd = ares[i]["password"];
      *_auth = ares[i]["authority"];
      if(strcmp(*_auth, "su") {
        users->push_back(new SuperUser(_name, _pswd);
      } else {
        users->push_back(new CommonUser(_name, _pswd);
      }
    } catch(BadQuery er) {

      return DatabaseException::badQuery(er);

    } catch(const BadConversion &er) {
      
      return DatabaseException::badConversion(er);

    } catch(const Exception &er) {
      
      return DatabaseException::exception(er);

    }
    return users;

  }

void UserMapper::saveUser(User *_user) {
  string _auth;
  if(_user->isSuper()) {
    auth = "su";
  } else {
    auth = "common";
  }

  try {
    Query query = this->conn.query();

    query << "INSERT INTO user" << "VALUES ("
          << _user->getName() << ", " << _user->getPswd()
          << ", " << _auth << "\"" << ");";
    query.execute();

  } catch(BadQuery er) {

    return DatabaseException::badQuery(er);
          
  } catch(const BadConversion &er) {

    return DatabaseException::badConversion(er);

  } catch(const Exception &er) {

    return DatabaseException::exception(er);

  }
}
