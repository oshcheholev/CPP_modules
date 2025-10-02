#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	virtual ~Serializer() = 0;

public:
    static uintptr_t serialize(Data* data);
    static Data* deserialize(uintptr_t ptr);
};
#endif // SERIALIZER_HPP
