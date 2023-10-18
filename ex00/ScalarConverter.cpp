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

ScalarConverter::ScalarConverter() : value((char *)"nan")
{}

ScalarConverter::ScalarConverter(char *input) : value(input)
{}

ScalarConverter::ScalarConverter(ScalarConverter &src) : value(src.value)
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
	this->value = src.value;
	return *this;
}

void ScalarConverter::convert() {
	double Double;
	bool numOnly = true;
	int dotAmount = 0;
	int minusAmount = 0;

	for (int i = 0; i < (int)strlen(this->value); ++i) {
		if (std::isdigit(this->value[i]) == false) {
			if (this->value[i] == '.') {
				dotAmount++;
				if (dotAmount > 1)
					numOnly = false;
			}
			if (this->value[i] == '-') {
				minusAmount++;
				if (minusAmount > 1)
					numOnly = false;
			}
			else {
				numOnly = false;
			}
		}
	}

	if (strlen(this->value) > 1 && numOnly == false)
		std::cout << "WARNING: multi char sequence input, strings lead to undefined behaviour, if you input nan or inf inputs, disregard this warning!" << std::endl;
	if (strlen(this->value) == 1 && std::isdigit(this->value[0]) == false) {
		Double = static_cast<double>(this->value[0]);
	}
	else
		Double = strtod(&this->value[0], NULL);

	toChar(Double);
	toInt(Double);
	toFloat(Double);
	toDouble(Double);
}

void ScalarConverter::toChar(double input) {
	char output;

	if (std::isnan(input) || std::isinf(input) || std::numeric_limits<int>::max() || std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else if (isprint((int)input)){
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
