#include "KeyPadLock.h"

KeyPadLock::KeyPadLock() {
}

KeyPadLock::~KeyPadLock() {
}

void KeyPadLock::openLock(User user) {
	cout << "KeyPadLock: User is " + user.name << endl;
	cout << "KeyPadLock  is now " << (getLockState() ? "opened" : "closed")
			<< endl;
	if (!getLockState()) {
		if (autenticateKeyData(user.pin)) {
			unlockFeedback();
			setLockState(true);
			cout << "KeyPadLock  is " << (getLockState() ? "opened" : "closed")
					<< endl;
			setLockState(false);
			cout << "User: " << user.name
					<< (getLockState() ? " opened" : " closed") << " the lock "
					<< endl;
		} else {
			cout << "KeyPadLock: User->" + user.name + " Failed to authenticate"
					<< endl;
			cout << "KeyPadLock remain "
					<< (getLockState() ? "opened" : "closed") << endl;
		}
	} else {
		cout << "KeyPadLock is already "
				<< (getLockState() ? "opened" : "closed") << endl;
	}
}

// Point 9
string KeyPadLock::getLockType() {
	return KeyPadLock::lockType;
}

bool KeyPadLock::getLockState() {
	return KeyPadLock::lockState;
}
void KeyPadLock::setLockState(bool lockState) {
	KeyPadLock::lockState = lockState;
}

bool KeyPadLock::autenticateKeyData(int pinKeyData) {
	if (pinKeyData == owner.pin) {
		return true;
	}
	return false;
}

User KeyPadLock::getOwnerData() {
	User owner("vishnu", 1234);
	return owner;
}

