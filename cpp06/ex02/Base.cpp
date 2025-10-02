#include "Base.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>  // for rand(), srand()
//#include <random>

Base::Base() {}
Base::~Base() {}

Base* generate(void) {
    int i = rand() % 3;

	switch (i) {
		case 0:{
			std::cout << "Generating A" << std::endl;
			return new A();
		}
		case 1:{
			std::cout << "Generating B" << std::endl;
			return new B();
		}
		case 2:{
			std::cout << "Generating C" << std::endl;
			return new C();
		}
		default:
			return NULL; // This should never happen, just protection
	}

}

// Identify by pointer
void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "This is A object identified by pointer" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "This is B object identified by pointer" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "This is C object identified by pointer" << std::endl;
	} else {
		std::cout << "Unknown type." << std::endl;
	}
}

// Identify by reference (no pointers allowed)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "This is A object identified by reference" << std::endl;
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "This is B object identified by reference" << std::endl;
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "This is C object identified by reference" << std::endl;
            } catch (...) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

