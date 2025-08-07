
#include <iostream>
#include <string>

template <typename T>
Array<T>::Array() {
			this->_array = new T[0];
			this->_size = 0;
	}

template <typename T>
Array<T>::Array(std::size_t size) {
	if (size == 0) {
		this->_array = new T[0];
		this->_size = 0;
	} else {
		this->_array = new T[size];
		this->_size = size;
		for (std::size_t i = 0; i < size; ++i) {
			this->_array[i] = T(); // Initialize with default value
		}
	}
}

template <typename T>
Array<T>::Array(const Array& other) {
	this->_size = other._size;
	if (this->_size > 0) {
		this->_array = new T[this->_size];
		for (std::size_t i = 0; i < this->_size; ++i) {
			this->_array[i] = other._array[i]; // Copy elements
		}
	} else {
		this->_array = new T[0];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] this->_array;
		this->_size = other._size;
		if (this->_size > 0) {
			this->_array = new T[this->_size];
			for (std::size_t i = 0; i < this->_size; ++i) {
				this->_array[i] = other._array[i]; // Copy elements
			}
		} else {
			this->_array = new T[0];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (this->_array) {
		delete[] this->_array;
	}
}

template <typename T>
T& Array<T>::operator[](std::size_t index) {
	if (index >= this->_size) {
		throw std::out_of_range("Index out of bounds");
	}
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
	if (index >= this->_size) {
		throw std::out_of_range("Index out of bounds");
	}
	return this->_array[index];
}

template <typename T>
std::size_t Array<T>::size() const {
	return this->_size;
}

