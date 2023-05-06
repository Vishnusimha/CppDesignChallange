#ifndef USER_H_
#define USER_H_
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class User {
public:
	string name;
	string password;
	int pin = 0;
	string fingerPrint;

	virtual ~User();
	User(string name);
	User(string name, int pin, string fingerPrint);
	User(string name, int pin);
	User(string name, string fingerPrint);
	void printUserDetails();
	void operator =(const User &user);
};

#endif /* USER_H_ */
