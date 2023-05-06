#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Lock.h"
#include "User.h"
#include "DigitalLock.h"
#include "KeyPadLock.h"
#include "FingerPrintLock.h"
#include "HybridLock.h"
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::count;

void userMaskPlanA(User x) {
//Point 5:
//this doesn't work because any changes happen to the x will be here in scope
//and cannot reflect in other place. Only in case of returning the object we can make use of this method
	if (x.name != "vishnu") {
		x.name = "vishnu";
	}
}

void userMaskPlanB(User &x) {
//Point 5:
//since the user enters by reference, whatever changes we make to the object will apply.
	if (x.name != "vishnu") {
		x.name = "vishnu";
	}
}

bool checkPower(HybridLock a, HybridLock b) {
//Point 11
//	overloaded > and == operators
	if (a > b || a == b) {
		cout << "true" << endl;
		return true;
	} else {
		cout << "false " << endl;
		return false;
	}
}

void checkUserAndDirect(User bankUser, HybridLock choosenLock,
		HybridLock androidKitkat, HybridLock appleCatalina,
		HybridLock androidPie, HybridLock windows) {
	if (bankUser.name == "vishnu" && (choosenLock > appleCatalina)) {
		cout << "User is vishnu" << endl;
		cout << "choosenLock is greater than appleCatalina" << endl;
		choosenLock.openLock(bankUser);
	} else {
		cout << "choosenLock is NOT greater than appleCatalina" << endl;
//Point 12 overloaded assignment(=) operator for chain operations
		choosenLock = androidPie = windows;
//The overloaded operator chain operations properly works so the securitylevel value here fall from 11 to 9
		cout << "securityLevel: of " << choosenLock.lockOS << " is "
				<< choosenLock.securityLevel << endl;
		HybridLock hyWindowsEleven = choosenLock + windows;
		checkPower(hyWindowsEleven, appleCatalina); //true
		hyWindowsEleven.openLock(bankUser);
	}
}

void display(HybridLock l) {
	cout << "l.lockOS: " << l.lockOS << endl;
	cout << "l.securityLevel: " << l.securityLevel << endl;
}

void displayUserDetails(User x) {
	cout << "User name: " << x.name << endl;
	cout << "User pin : " << x.pin << endl;
	cout << "User fingerPrint : " << x.fingerPrint << endl;
}

int main() {
//	Point 13 passing object itself to a fun implemented in User Class.
	User robot = User("robot");
	robot.printUserDetails();

	//Point 5: call by value and call by reference
	HybridLock hybridLock = HybridLock("hylock", 10);
	User lucas = User("lucas", 1234, "fingerprint");
	userMaskPlanA(lucas); //access fails because lucas cannot mask as vishnu
	hybridLock.openLock(lucas);
	userMaskPlanB(lucas); //lucas got access because he changed his name to vishnu by reference
	hybridLock.openLock(lucas);

	//Point 10
	//dynamic binding virtual methods
	DigitalLock dlock;
	dlock.printLockType();
	KeyPadLock klock;
	klock.printLockType();

	//	Point 11 & Point 12
	HybridLock appleCatalina = HybridLock("catalina", 11);
	HybridLock appleMontery = HybridLock("Montery", 12);
	HybridLock androidKitkat = HybridLock("kitkat", 5);
	HybridLock androidPie = HybridLock("pie", 7);
	HybridLock windows = HybridLock("windows10", 10);
	User bankUser = User("vishnu", 1234, "fingerprint");

	checkUserAndDirect(bankUser, androidKitkat, androidKitkat, appleCatalina,
			androidPie, windows); // androidKitkat is not greater than appleCatalina

	checkUserAndDirect(bankUser, appleMontery, androidKitkat, appleCatalina,
			androidPie, windows); // appleMontery is greater than appleCatalina

	//Point 14 Modified copy constructor
	HybridLock aa = HybridLock("catalina", 11);
	HybridLock bb(aa);
	cout << "aa.securityLevel = " << aa.securityLevel << endl;
	cout << " bb.securityLevel = " << bb.securityLevel << endl;

	HybridLock *cc = new HybridLock("testOS", 5);
//	security level wont fall by one for dd because we are passing by reference
	HybridLock *dd(cc);
	cout << "cc.securityLevel = " << cc->securityLevel << endl;
	cout << " dd.securityLevel = " << dd->securityLevel << endl;

	//Point 18
	//created a vector for 3 Hybrid Locks and used a vector function for_each to display its elements.
	vector<HybridLock> vectorHy { HybridLock("a", 2), HybridLock("a", 2),
			HybridLock("b", 3), HybridLock("c", 4) };

	//	Point 19 used count and for_each algorithms
	int count = std::count(vectorHy.begin(), vectorHy.end(),
			HybridLock("a", 2));
	cout << "COUNT=====" << count << endl;
	for_each(vectorHy.begin(), vectorHy.end(), display);

//Point 20 Smart pointer Unique
	unique_ptr<HybridLock> uniqueHyLock(
			new HybridLock("Rare Custom lock OS", 100));

	cout << "unique ptr : " << uniqueHyLock->lockOS << endl;
//here i am not able to copy it as a normal HybridLock and i can only copy it as a unique pointer
//HybridLock copiedUniquelock = move(uniqueHyLock); // Not possible
	unique_ptr<HybridLock> copiedUniquelock = move(uniqueHyLock);
	cout << "unique ptr Moved : " << copiedUniquelock->lockOS << endl;

// Point 15 Explicit casing
	DigitalLock b = DigitalLock();
	b.printLockType();
	DigitalLock *a = new DigitalLock();
	a->printLockType();
	KeyPadLock *k = dynamic_cast<KeyPadLock*>(a);
	a->printLockType();
	k->printLockType();

//Point 8
//created array of pointers for a class User and displaying it elements by passing to a function
	int i;
	User *testUsers[3];
	testUsers[0] = new User("name1", 12, "fp1");
	testUsers[1] = new User("name2", 13, "fp2");
	testUsers[2] = new User("name3", 14, "fp3");
	for (i = 0; i <= 3; i++) {
		displayUserDetails(*testUsers[i]);
	}

//	delete testUsers[3];
	//Point 7
	//accessing HybridLock &
	//Demonstrated 2 ways of calling a destructor,
	//one by calling destructor and another by using delete keyword.
	HybridLock dynamicLock = HybridLock("dynamicLock", 11);
	User *sunith = new User("sunith", 1234, "fingerprint");
	dynamicLock.openLock(*sunith);
	//cleaning dynamically allocated memory with delete,
	//so we cannot know what output it gives when we use the object again after deallocating memory.
	delete sunith;
	dynamicLock.openLock(*sunith);
	//Point 9: calls the destructor of User which in reality doesn't clear/ deallocate the object memory
	sunith->~User();

//................................................................
// Below are the general lock accessing implementations
//	//accessing digital lock with owner
	DigitalLock digitalLock = DigitalLock();
	User *owner = new User("vishnu", 1234, "myfpdata");
	digitalLock.openLock(*owner);

	//accessing digital lock with random person/wrong password
	User *random = new User("simha", 12, "myfpdata");
	digitalLock.openLock(*random);

	// accessing fingerPrintLock
	FingerPrintLock fpLock;
	User *ajay = new User("Ajay", 1234, "fingerprint");
	fpLock.openLock(*ajay);

	// accessing KeyPadLock
	KeyPadLock *keypadLock = new KeyPadLock();
	User *john = new User("John", 1234);
	keypadLock->openLock(*john);

	//accessing HybridLock
	HybridLock lk = HybridLock("sas", 11);
	User one = User("one", 1234, "fingerprint");
	User two = User("two", 1234, "fingerprint");
	two = one;
	two.printUserDetails();
	one.printUserDetails();
	lk.openLock(one);

	DigitalLock *ss = new DigitalLock();
	KeyPadLock *c = new KeyPadLock();
	c = (KeyPadLock*) ss;
	c->getLockState();

	return 0;
}
