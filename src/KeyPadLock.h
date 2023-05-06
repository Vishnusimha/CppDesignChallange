#ifndef KEYPADLOCK_H_
#define KEYPADLOCK_H_
#include "User.h"
#include "DigitalLock.h"
#include <iostream>
using std::cout;
using std::endl;

class KeyPadLock: public DigitalLock {

public:
	KeyPadLock();
	virtual ~KeyPadLock();
	virtual void openLock(User user);
	bool getLockState();
//Point 10 Dynamic binding
//getLockType() gets called based on the object type when its virtual. otherwise it calls the same method in parent class;
	virtual string getLockType();

protected:
	virtual void setLockState(bool lockState);

private:
	string lockType = "KeyPadLock";
	User owner = getOwnerData();
	bool lockState = false;

	virtual bool autenticateKeyData(int pinKeyData);
	virtual User getOwnerData();
};

#endif /* KEYPADLOCK_H_ */
