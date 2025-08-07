#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>
#include <cstdint>



#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}


int main(void) {

    printTitle("Normal Case");
    Data original = {42, "Hello, World!", 3.14};

    // original
    std::cout << GREEN << "Original Data:" << RESET << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Value: " << original.value << std::endl;
    std::cout << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &original) {
        std::cout << GREEN << "SUCCESS" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE" << RESET << std::endl;
    }

    std::cout << CYAN << "Deserialize:" << RESET << std::endl;
    std::cout << "ID: " << ptr->id << std::endl;
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;
    std::cout << std::endl;

    printTitle("Pointer Modifying");
    ptr->id = 5;
    ptr->name = "Hello World Modified";
    ptr->value = 42.42;

    std::cout << CYAN << "Pointer Data:" << RESET << std::endl;
    std::cout << "ID: " << ptr->id << std::endl;
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "Original Data:" << RESET << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Value: " << original.value << std::endl;
    std::cout << std::endl;


    printTitle("Null Pointer");
    Data* nullPtr = NULL;
    uintptr_t nullRaw = Serializer::serialize(nullPtr);
    std::cout << "Serialized null pointer value: " << nullRaw << std::endl;
    
    Data* dNull = Serializer::deserialize(nullRaw);
    if (dNull == NULL) {
        std::cout << GREEN << "SUCCESS Nullptr" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE Nullptr" << RESET << std::endl;
    }
    std::cout << std::endl;

    printTitle("Zero Value");
    Data* zeroPtr = Serializer::deserialize(0); 
    if (zeroPtr == NULL) {
        std::cout << GREEN << "SUCCESS Zero" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE Zero" << RESET << std::endl;
    }

}

