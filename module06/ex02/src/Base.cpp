#include "Base.hpp"

Base * Base::generate(void) {

}

void Base::identify(Base* p) {
	if (std::dynamic_cast<A*>(p)) {

	}
}

void Base::identify(Base& p) {

}

