#include "A.hpp"
#include "functions.hpp"

int main(void) {
	Base* p = generate();
	identify(p);
	identify(*p);
}