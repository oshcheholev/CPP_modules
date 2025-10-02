#include "Serializer.hpp"
#include "Data.hpp"


Serializer::Serializer() {} // Default constructor
Serializer::Serializer(const Serializer& other) { (void)other; } // Copy constructor
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; } // Copy assignment operator
Serializer::~Serializer() {} // Destructor

uintptr_t Serializer::serialize(Data* ptr)
{
	// Check if the pointer is null
	if (ptr == NULL)
		return 0;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	// Check if the raw pointer is null
	if (raw == 0)
		return NULL;
	return reinterpret_cast<Data*>(raw);
	
}
 