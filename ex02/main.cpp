#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "B.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "functions.hpp"

int main(void) {
	Base* p = generate();
	identify(p);
	identify(p);
}