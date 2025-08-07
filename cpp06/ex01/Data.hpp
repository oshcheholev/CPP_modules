#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int id;
    std::string name;
	float value;

	Data(int id, const std::string& name, float value)
		: id(id), name(name), value(value) {}
};

#endif // DATA_HPP
