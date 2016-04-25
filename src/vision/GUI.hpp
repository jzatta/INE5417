#ifndef _GUI_
#define _GUI_

class GUI;

#include <iostream>
#include <string>

class GUI{
private:

public:

	void permissionException(); // just say if user has or not permission to do the action
	void userCreated(); // just say if user was created or not
	void fileCreated(); // just say if file was created or not
	void deleteNotification(const string _type, string *_verify); // @type assumes file or user, @verify tells if file/user was sucessfully removed
	string *fileName(const string _param); // @_param is a parameter in UI to tell if is a add or delete method
	string *userName(const string _param); // @_param is a parameter in UI to tell if is a add or delete method
	string *userPswd(); // get the user password from the keyboard
	string *userResp(); // ask if user is a common user or a supper user
};
#endif