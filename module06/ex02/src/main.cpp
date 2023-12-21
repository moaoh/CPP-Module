#include <iostream>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
  int randNum = rand() % 3;
  if (randNum == 0) {
    return (new A());
  }
	else if (randNum == 1) {
    return (new B());
  }
	else {
    return (new C());
  }
}

void identify(Base *p) {
  std::cout << "*p: ";
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "A" << std::endl;
	}
  else if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "B" << std::endl;
	}
  else if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
  try {
		A &a = dynamic_cast<A&>(p);
    std::cout << "&p: A" << std::endl;
		static_cast<void>(a);
  }
  catch (std::bad_cast) {}
  try {
		B &b = dynamic_cast<B&>(p);
    std::cout << "&p: B" << std::endl;
		static_cast<void>(b);
  }
  catch (std::bad_cast) {}
  try {
		C &c = dynamic_cast<C&>(p);
    std::cout << "&p: C" << std::endl;
		static_cast<void>(c);
  }
  catch (std::bad_cast) {}
}

int main(void) {
  std::srand(time(NULL));

  for (int i = 1; i <= 10; i++) {
    Base *p = generate();
    std::cout << "generate :" << i << std::endl;
    identify(p);
    identify(*p);
  }
	return (0);
}
