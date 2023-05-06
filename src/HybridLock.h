#ifndef HYBRIDLOCK_H_
#define HYBRIDLOCK_H_
#include <iostream>
#include "User.h"
#include "FingerPrintLock.h"
#include "KeyPadLock.h"
using std::cout;

//Point 1: Multiple Inheritance: inherited both FingerPrintLock & KeyPadLock
class HybridLock: public FingerPrintLock, KeyPadLock {
public:
	int securityLevel;
	string lockOS;
	HybridLock(string lockOS, int securityLevel);
//	HybridLock(HybridLock hybridlock);
	//Point
	//Point 14
	//modified copy constructor
	HybridLock(const HybridLock &inputHybridLock);
	virtual ~HybridLock();

	//operator overloading : over loaded == > and + operators
	bool operator ==(HybridLock);
	bool operator >(HybridLock hybridLock);
	HybridLock operator +(HybridLock);
	HybridLock& operator =(const HybridLock &hybridlock);
	virtual void openLock(User user);

protected:
	virtual void setLockOs(string lockOS);
	virtual void setSecurityLevel(int securityLevel);
	virtual void setCustomTheme(string customTheme);

private:
	string lockType = "HybridLock";
	string fingerPrintInput;
	string customTheme;
	User owner = getOwnerData();

	bool lockState = false;
	virtual bool getLockState();
	virtual void setLockState(bool lockState);
	virtual bool autenticateKeyData(string fingerPrintkeyData);
	virtual bool autenticateKeyData(int pinKeyData);
	User getOwnerData();
};

#endif /* HYBRIDLOCK_H_ */
