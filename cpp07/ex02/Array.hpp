#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array {
private:
	T* _array;
	std::size_t _size;
public:
	Array();
	Array(std::size_t size);

	~Array();

	Array(const Array& other);

	Array& operator=(const Array& other);

	T& operator[](std::size_t index);

	const T& operator[](std::size_t index) const;

	std::size_t size() const;

};

#endif