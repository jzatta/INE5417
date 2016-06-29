
#include "user_mapper.hpp"

// C/C++ includes
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <mysql++.h>

// other classes includes
#include "user.hpp"
#include "superUser.hpp"
#include "commonUser.hpp"
#include "user_mapper.hpp"
#include "connect.hpp"
#include "databaseException.hpp"

using namespace std;
using namespace mysqlpp;

list<User*> *UserMapper::loadUsers() {
  string *_name;
  string *_pswd;
  string *_auth;
  list<User*> *users = new list<User*>();
  try {
    Query query = Connect::getConnection()->query();

    query << "SELECT * FROM username";
    StoreQueryResult ares = query.store();
    for(size_t i = 0; i < ares.num_rows(); i++) {
      _name = new string(ares[i]["name"]);
      _pswd = new string(ares[i]["password"]);
      _auth = new string(ares[i]["authority"]);
      if(!strcmp(_auth->c_str(), "su")) {
        users->push_back(new SuperUser(_name, _pswd));
      } else {
        users->push_back(new CommonUser(_name, _pswd));
      }
    }
  } catch (BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch (const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch (const Exception &er) {
    throw DatabaseException::exception(er);
  }
  return users;


void UserMapper::saveUser(User *_user) {
  string _auth;
  if(_user->isSuper()) {
    _auth = "su";
  } else {
    _auth = "common";
  }

  try {
    Query query = Connect::getConnection()->query();

    query << "INSERT INTO `username`" << "VALUES ('"
          << _user->getName()->c_str() << "', '" << _user->getPswd()->c_str()
          << "', '" << _auth << "'" << ");";
    query.execute();

  } catch (BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch (const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch (const Exception &er) {
    throw DatabaseException::exception(er);
  }
}

void UserMapper::deleteUser(string *_usrName) {
  try {
    Query query = Connect::getConnection()->query();

    query << "DELETE FROM username WHERE name = '"
          << *_usrName << "'";

    query.execute();
  } catch(BadQuery er) {
    throw DatabaseException::badQuery(er);
  } catch(const BadConversion &er) {
    throw DatabaseException::badConversion(er);
  } catch(const Exception &er) {
    throw DatabaseException::exception(er);
  }
}
