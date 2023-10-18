#ifndef CPP06_SCALARCONVERTER_HPP
#define CPP06_SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	char *value;
public:
	ScalarConverter();
	ScalarConverter(char *input);
	ScalarConverter(ScalarConverter &src);
	~ScalarConverter();

	void convert();
	void toChar(double input);
	void toInt(double input);
	void toDouble(double input);
	void toFloat(double input);

	ScalarConverter &operator=(ScalarConverter const &src);
};

#endif //CPP06_SCALARCONVERTER_HPP
