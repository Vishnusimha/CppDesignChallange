#include "User.h"

void markAsVulnerable(User &user){
	user.name = "vulnerable user";
}

User::User(string name) {
	this->name = name;
	// TODO Auto-generated constructor stub
}

//Constructor overloading
User::User(string name, int pin, string fingerPrint) {
	this->name = name;
	this->pin = pin;
	this->fingerPrint = fingerPrint;
}

User::User(string name, int pin) {
	this->name = name;
	this->pin = pin;
}

User::User(string name, string fingerPrint) {
	this->name = name;
	this->fingerPrint = fingerPrint;
}

User::~User() {
//	Point 9
//	cout << "User destructor called " << endl;
// delete ptr; delete any pointers in destructor to deallocate dynamically allocated memory
}

// operator overloading permitted only for hybrid lock
void User::operator =(const User &user) {
	this->name = name;
	this->pin = pin;
	this->fingerPrint = fingerPrint;
}

// Point 13 object passing itself to a function.
void User::printUserDetails() {
	cout << this->name << endl;
	markAsVulnerable(*this);
	cout << this->name << endl;
}

