#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer& src);
public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer& operator=(const Serializer& src);
};

#endif //CPP06_SERIALIZER_HPP
