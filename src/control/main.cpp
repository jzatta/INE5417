#include "user.hpp"
#include "usermanager.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
	User x;
	x.setName("Noel");
	x.setPswd("x78s22");
  list<User> L;
  L.insert(x);
  UserManager y = new UserManager();
  y.create(x);
	cout << x.getName() << endl;
	cout << x.getPswd() << endl;
	return 0;
}
