#include "connect.hpp"
#include <iostream>
#include <stdlib.h>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

void Connect::connect_db() {
  try {
    Connection conn(false);
    conn.connect("root", "localhost", "root", "root");
    Query query = conn.query();
  } catch (BadQuery er) { // catch errors that may come up yo
    cerr << "Error: " << er.what() << endl;
    return -1;
  } catch (const BadConversion &er) { // catch bad conversions
    cerr  << "Conversion error: " << er.what() << endl
          << "\tretrieved data size: " << er.retrieved
          << ", actual size: " << er.actual_size << endl;
    return -1;
  } catch (const Exception &er) {
    // catch all any other mysql++ exceptions
    cerr << "Error: " << er.what() << endl;
    return -1;
  }

  //return(EXIT_SUCCESS);
}
