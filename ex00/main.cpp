#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char*argv[])
{
	if (argc != 2) {
		std::cout << "wrong amount of inputs" << std::endl;
		return(1);
	}

	ScalarConverter a(argv[1]);
	a.convert();

}

