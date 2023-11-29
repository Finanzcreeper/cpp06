#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


Base * generate() {
	Base *output;
	int i;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	i = std::rand() % 3;
	switch (i) {
		case 1:
			output = new A;
			break;
		case 2:
			output = new B;
			break;
		default:
			output = new C;
			break;
	}
	return (output);
}

void identify(Base* p) {
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a != NULL) {
		std::cout << "this pointer is of type A" << std::endl;
		return;
	}
	if (b != NULL) {
		std::cout << "this pointer is of type B" << std::endl;
		return;
	}
	if (c != NULL) {
		std::cout << "this pointer is of type C" << std::endl;
		return;
	}
}

void identify(Base& p){
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "this reference is of type A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout << "this reference is of type B" << std::endl;
			(void)b;
		}
		catch (std::exception &e){
			try {
				C& c = dynamic_cast<C&>(p);
				std::cout << "this reference is of type C" << std::endl;
				(void)c;
			}
			catch (std::exception &e) {
				std::cout << "this reference is of no valid type" << std::endl;
			}
		}
	}
}
