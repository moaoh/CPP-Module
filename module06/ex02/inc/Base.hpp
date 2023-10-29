#ifndef BASE_HPP_
#define BASE_HPP_

#include <iostream>

class A;
class B;
class C;

class Base {
public:
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
private:
};

#endif
