#ifndef CPP06_SCALARCONVERTER_HPP
#define CPP06_SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	~ScalarConverter();

	static void convert(char *value);
	static void toChar(double input);
	static void toInt(double input);
	static void toDouble(double input);
	static void toFloat(double input);

};

#endif //CPP06_SCALARCONVERTER_HPP
