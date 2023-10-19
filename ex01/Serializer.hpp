#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:

	Serializer();
	Serializer(Serializer& src);

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

	Serializer& operator=(const Serializer& src);
};

#endif //CPP06_SERIALIZER_HPP
