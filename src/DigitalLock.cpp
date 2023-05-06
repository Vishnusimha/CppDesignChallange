#include "DigitalLock.h"

//Point 16 Static states and methods
string DigitalLock::positiveLight = "Green";
string DigitalLock::negativeLight = "Red";

//Point 16 Static states and methods
void DigitalLock::informPolice() {
	cout << DigitalLock::negativeLight << "SOS Intruder" << endl;
}

DigitalLock::DigitalLock() :
		Lock() {
	init();
}

void DigitalLock::init() {
	runDigitalScheme();
	startScreenDisplay();
	displayLockName();
}

DigitalLock::~DigitalLock() {

}

void DigitalLock::openLock(User user) {
	cout << "Digital lock: User name is " + user.name << endl;
	cout << "DigitalLock  is now " << (getLockState() ? "opened" : "closed")
			<< endl;

	if (!getLockState()) {
		if (autenticateKeyData(user.pin)) {
			setLockState(true);
			unlockFeedback();
			cout << "Digital Lock " << (getLockState() ? "opened" : "closed")
					<< endl;
			setLockState(false);
			cout << "User: " << user.name
					<< (getLockState() ? " opened" : " closed") << " the lock "
					<< endl;
		} else {
			cout << "DigitalLock access failed" << endl;
			cout << "Digital Lock remain"
					<< (getLockState() ? "opened" : "closed") << endl;
			informPolice();
		}
	}
}

void DigitalLock::digitalLockType(string lockType) {
	cout << "lockType" + lockType << endl;
}

void DigitalLock::unlockFeedback() {
	soundBeep();
}

bool DigitalLock::getLockState() {
	return DigitalLock::lockState;
}

// Point 10
string DigitalLock::getLockType() {
	return DigitalLock::lockType;
}

// Point 10
void DigitalLock::printLockType() {
	cout << " Lock type: " << getLockType() << endl;
}


User DigitalLock::getOwnerData() {

	User owner("vishnu", 1234);
	return owner;
}

bool DigitalLock::autenticateKeyData(int pinKeyData) {
	if (pinKeyData == owner.pin) {
		cout << "DigitalLock: User Data is " << pinKeyData << endl;
		return true;
	}
	return false;
}

void DigitalLock::runDigitalScheme() {
	cout << "DigitalLock: Running digital lock schema" << endl;
}

void DigitalLock::startScreenDisplay() {
	cout << "DigitalLock: Showing startScreenDisplay" << endl;
}

void DigitalLock::soundBeep() {
	cout << "Sound:: Lock Beeps..." << endl;
}

void DigitalLock::displayLockName() {
	cout << "DigitalLock is ready to provide access" << endl;
}

void DigitalLock::setLockState(bool lockState) {
	DigitalLock::lockState = lockState;
}

