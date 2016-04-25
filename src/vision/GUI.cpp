#include <iostream>
#include <string>
#include "GUI.hpp"
#include "UI.hpp"

using namespace std;

void permissionException() {
	cout << "acess denied" << endl;
	UI::pause();
}

string *addFile() {
	char name[100];
  	UI::clearScreen();
  	cout << "Insert file name" << endl;
  	cin.getline(name, sizeof(name));  
  	cout << "File created" << endl;
  	UI::pause();
  	return new string(name);
}