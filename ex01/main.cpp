#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>


int main() {
	Data *Datas;
	Serializer Serializer;
	uintptr_t Serial;
	Data *Remade;

	Datas = new Data;
	std::cout << "filling string in struct with \"test\"" << std::endl;
	Datas->string = "test";
	std::cout << "Serializing Data Pointer: " << &Datas << " to: ";
	Serial = Serializer.serialize(Datas);
	std::cout << Serial << std::endl;
	std::cout << "Unserialising: " << Serial << " to: ";
	Remade = Serializer.deserialize(Serial);
	std::cout << Remade << std::endl;
	std::cout << "The string in the remade pointer contains: " << Remade->string << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << Serializer.deserialize(Serializer.serialize(Datas))->string << std::endl;
	std::cout << std::endl << std::endl;
}