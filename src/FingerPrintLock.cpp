#include "FingerPrintLock.h"
#include "KeyPadLock.h"

FingerPrintLock::FingerPrintLock() {
}

FingerPrintLock::~FingerPrintLock() {
}

void FingerPrintLock::openLock(User user) {
	cout << "FingerPrintLock: User is " + user.name << endl;
	cout << "FingerPrintLock  is now " << (getLockState() ? "opened" : "closed")
			<< endl;

	if (!getLockState()) {
		if (autenticateKeyData(user.fingerPrint)) {
			setLockState(true);
			unlockFeedback();
			cout << "FingerPrintLock  is "<< (getLockState() ? "opened" : "closed") << endl;
			cout << "Shows" << positiveLight << " Light";
			setLockState(false);
			cout << "User: " << user.name<< (getLockState() ? " opened" : " closed") << " the lock "
					<< endl;
		} else {
			cout<< "FingerPrintLock: User->" + user.name+ " Failed to authenticate" << endl;
			unlockFeedback();
			setLockState(true);
			cout << "FingerPrintLock remain "<< (getLockState() ? "opened" : "closed") << endl;
		}
	} else {
		cout << "FingerPrintLock is already "<< (getLockState() ? "opened" : "closed") << endl;
	}
}

bool FingerPrintLock::getLockState() {
	return FingerPrintLock::lockState;
}

bool FingerPrintLock::autenticateKeyData(string fingerPrint) {
	return (fingerPrint == owner.fingerPrint) ? true : false;;
}

void FingerPrintLock::setLockState(bool lockState) {
	FingerPrintLock::lockState = lockState;
}

User FingerPrintLock::getOwnerData() {
	User owner("vishnu", "fingerprint");

	return owner;
}

