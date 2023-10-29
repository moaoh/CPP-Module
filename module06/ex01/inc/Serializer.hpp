#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <iostream>


struct Data {
	std::string name;
};

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer& src);
	Serializer &operator=(const Serializer& rhs);
	~Serializer();
};

#endif
