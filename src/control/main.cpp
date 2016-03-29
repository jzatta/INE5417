#include "user.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
	User x;
	x.setName("Noel");
	x.setPswd("x78s22");
	cout << x.getName() << endl;
	cout << x.getPswd() << endl;
	return 0;
}