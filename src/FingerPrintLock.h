#ifndef FINGERPRINTLOCK_H_
#define FINGERPRINTLOCK_H_
#include <iostream>
using std::cout;
using std::endl;
#include "User.h"
#include "DigitalLock.h"

class FingerPrintLock: public DigitalLock {
public:
	FingerPrintLock();
	virtual ~FingerPrintLock();
	virtual void openLock(User user);

private:
	string fingerPrintInput;
	User owner = getOwnerData();

	bool lockState = false;
	virtual bool getLockState();
	virtual void setLockState(bool lockState);

	virtual bool autenticateKeyData(string fingerPrint);
	virtual User getOwnerData();
};

#endif /* FINGERPRINTLOCK_H_ */
