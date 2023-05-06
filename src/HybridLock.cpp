#include "HybridLock.h"
#include "User.h"
#include <iostream>
using std::cout;

HybridLock::HybridLock(string lockOS, int securityLevel) {
	cout << "H L constructor" << endl;
	this->lockOS = lockOS;
	this->securityLevel = securityLevel;
}

//Point 14 Modified copy constructor
HybridLock::HybridLock(const HybridLock &inputHybridLock) {
	cout << "H L COPY constructor" << endl;
	this->lockOS = inputHybridLock.lockOS;
//	security level fall by one when someone and copy this Lock
	this->securityLevel = inputHybridLock.securityLevel - 1;
}

//Point 12 operator overloading
HybridLock& HybridLock::operator =(const HybridLock &hybridLock) {
	cout << "H L  = constructor" << endl;
	if (this != &hybridLock) {
		lockOS = hybridLock.lockOS;
		securityLevel = hybridLock.securityLevel;
	}
	return *this;
}
//Point 11 operator overloading
bool HybridLock::operator ==(HybridLock hybridLock) {
	if (hybridLock.securityLevel == securityLevel
			&& hybridLock.lockOS == lockOS) {
		return true;
	} else {
		return false;
	}
}
//Point 11 operator overloading
HybridLock HybridLock::operator +(HybridLock hybridLock) {
	return HybridLock(lockOS, securityLevel + hybridLock.securityLevel);
}
//Point 11 operator overloading
bool HybridLock::operator >(HybridLock hybridLock) {
	if (securityLevel > hybridLock.securityLevel) {
		return true;
	} else {
		return false;
	}
}

HybridLock::~HybridLock() {
}

void HybridLock::setLockOs(string lockOS) {
	this->lockOS = lockOS;
}
void HybridLock::setSecurityLevel(int securityLevel) {
	this->securityLevel = securityLevel;
}

void HybridLock::openLock(User user) {
	cout << "HybridLock user name is: " + user.name << endl;
	cout << "HybridLock  is now " << (getLockState() ? "opened" : "closed")
			<< endl;
	if (!getLockState()) {
		if (user.pin != 0 || user.fingerPrint != "") {
			if (autenticateKeyData(user.fingerPrint) == true
					&& autenticateKeyData(user.pin) == true
					&& user.name == "vishnu") {
				setLockState(true);
				FingerPrintLock::unlockFeedback();
				cout << "HybridLock  is "
						<< (getLockState() ? "opened" : "closed") << endl;
				cout << "Shows" << positiveLight << " Light";
			} else {
				cout << "HybridLock: Access Failed for the User: " + user.name
						<< endl;
				cout << "HybridLock remain "
						<< (getLockState() ? "opened" : "closed") << endl;
				cout << "Shows" << this->lockOS << " Light";

				informPolice();
			}
		}
	}
}

void HybridLock::setCustomTheme(string customTheme) {
	this->customTheme = customTheme;
	cout << "Hybrid Lock: customTheme is " << customTheme << endl;
}

bool HybridLock::getLockState() {
	return HybridLock::lockState;
}

void HybridLock::setLockState(bool lockState) {
	HybridLock::lockState = lockState;
}
// function overloading
bool HybridLock::autenticateKeyData(string fingerPrintkeyData) {
	if (fingerPrintkeyData == owner.fingerPrint) {
		cout << "fingerPrint Data matched" << endl;
		return true;
	}
	return false;
}

bool HybridLock::autenticateKeyData(int pinKeyData) {
	if (pinKeyData == owner.pin) {
		cout << "Hybrid Lock: User pin Data matched" << endl;
		return true;
	}
	return false;
}

User HybridLock::getOwnerData() {
	User owner("vishnu", 1234, "fingerprint");
	return owner;
}
