#ifndef LOCK_H_
#define LOCK_H_
#include <iostream>
#include "User.h"
using std::cout;

//Point 3: Abstract Class with pure virtual functions
class Lock {
public:
	virtual void openLock(User user)= 0;
	virtual bool getLockState() =0;
	Lock();
	virtual ~Lock();
};

#endif /* LOCK_H_ */
