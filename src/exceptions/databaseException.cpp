#include <iostream>
#include <stdlib.h>
#include <mysql++.h>
#include <"databaseExceptions.hpp">

using namespace std;
using namespace mysqlpp;

int DatabaseException::badQuery(BadQuery er) {
  cerr << "Error: " << er.what() << endl;
  return -1;
}

int DatabaseException::badConversion(const BadConversion &er) {
  cerr  << "Conversion error: " << er.what() << endl
        << "\tretrieved data size: " << er.retrieved
        << ", actual size: " << er.actual_size << endl;
  return -1;
}

int DatabaseException::exception(const Exception &er) {
  cerr << "Error: " << er.what() << endl;
  return -1;
}
