#ifndef _GUI_
#define _GUI_

class GUI;

#include <iostream>
#include <string>

using namespace std;

class GUI{
private:

public:

	static void permissionException(); // just say if user has or not permission to do the action
	static void userCreated(); // just say if user was created or not
	static void fileCreated(); // just say if file was created or not
	static void deleteNotification(string *_type, string *_verify); // @type assumes file or user, @verify tells if file/user was sucessfully removed
	static string *getFileName(const char *_param); // @_param is a parameter in UI to tell if is a add or delete method
	static string *getUserName(const char *_param); // @_param is a parameter in UI to tell if is a add or delete method
	static string *getUserPswd(); // get the user password from the keyboard
	static bool getUserResp(); // ask if user is a common user or a supper user
  
  static string *getUserLogin();
  static string *getPswdLogin();
  static void clearScreen();
  static void pause();
};
#endif