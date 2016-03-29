#include <iostream>
#include <string>

using namespace std;

class User {
private:
	string name;
	string pswd;

public:
	User();
	User(string name, string pswd);
	/*
		getters and setters
	*/
	string getName();
	string getPswd();
	void setName(string name);
	void setPswd(string pswd);
};