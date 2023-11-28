//
// Created by nreher on 10/17/23.
//
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <limits>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(char *value) {
	double Double;
	bool numOnly = true;
	int dotAmount = 0;
	int minusAmount = 0;

	for (int i = 0; i < (int)strlen(value); ++i) {
		if (std::isdigit(value[i]) == false) {
			if (value[i] == '.') {
				dotAmount++;
				if (dotAmount > 1)
					numOnly = false;
			}
			if (value[i] == '-') {
				minusAmount++;
				if (minusAmount > 1)
					numOnly = false;
			}
			else {
				numOnly = false;
			}
		}
	}

	if (strlen(value) > 1 && numOnly == false)
		std::cout << "WARNING: multi char sequence input, strings lead to undefined behaviour, if you input nan or inf inputs, disregard this warning!" << std::endl;
	if (strlen(value) == 1 && std::isdigit(value[0]) == false) {
		Double = static_cast<double>(value[0]);
	}
	else
		Double = strtod(&value[0], NULL);

	toChar(Double);
	toInt(Double);
	toFloat(Double);
	toDouble(Double);
}

void ScalarConverter::toChar(double input) {
	char output;

	if (std::isnan(input) || std::isinf(input) || input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else if (( input >= 7 && input <= 13 ) || ( input >= ' ' && input < 127 )){
		output = static_cast<char>(input);
		std::cout << "char: '" << output << "'" << std::endl;
	}
	else
		std::cout << "char: not printable" << std::endl;
}

void ScalarConverter::toInt(double input) {
	int output;

	if (std::isnan(input) || std::isinf(input) || input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else {
		output = static_cast<int>(input);
		std::cout << "int: " << output << std::endl;
	}
}

void ScalarConverter::toDouble(double input) {
	double output;
	output = static_cast<double>(input);
	std::cout << "double: " << output << std::endl;
}

void ScalarConverter::toFloat(double input) {
	double output;
	output = static_cast<float>(input);
	std::cout << "float: " << output << "f" << std::endl;
}
