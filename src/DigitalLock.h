#ifndef DIGITALLOCK_H_
#define DIGITALLOCK_H_
#include <iostream>
using std::cout;
#include "User.h"
#include "Lock.h"

//Point 3 : Inherited abstract Lock class in Implemented the unimplemented pure virtual functions.
class DigitalLock: public Lock {

public:
	DigitalLock();
	virtual ~DigitalLock();
	virtual void openLock(User user);

	static string positiveLight;
	static string negativeLight;
	static void informPolice();
	void printLockType();

protected:
	void unlockFeedback();
	bool lockState = false;
	virtual void setLockState(bool lockState);
	virtual bool getLockState();
	//	overriden getLockType
	virtual string getLockType();
private:
	string lockType = "Digital Lock";
	User owner = getOwnerData();
	void init();

	virtual void digitalLockType(string lockType);
	virtual bool autenticateKeyData(int keyData);
	virtual void startScreenDisplay();
	virtual void runDigitalScheme();
	virtual User getOwnerData();
	virtual void displayLockName();
	virtual void soundBeep();

};

#endif /* DIGITALLOCK_H_ */
