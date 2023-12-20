#include <iostream>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
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
  std::cout << "&p: ";
  if (dynamic_cast<A *>(&p) != nullptr) {
    std::cout << "A" << std::endl;
	}
  else if (dynamic_cast<B *>(&p) != nullptr) {
    std::cout << "B" << std::endl;
	}
  else if (dynamic_cast<C *>(&p) != nullptr) {
    std::cout << "C" << std::endl;
	}
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
