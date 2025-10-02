#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>




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
    Data original = {0, "Hello, World!", 3.14};

    // original
    std::cout << GREEN << "Original Data:" << RESET << std::endl;
    std::cout << "INT: " << original.data_int << std::endl;
    std::cout << "STRING: " << original.data_string << std::endl;
    std::cout << "FLOAT: " << original.data_float << std::endl;
    std::cout << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &original) {
        std::cout << GREEN << "SUCCESS! Pointer == Original" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE! Pointer != Original" << RESET << std::endl;
    }
    std::cout << "Deserializing" << std::endl;
    std::cout << CYAN << "Deserialized Data:" << RESET << std::endl;
    std::cout << "INT: " << ptr->data_int << std::endl;
    std::cout << "STRING: " << ptr->data_string << std::endl;
    std::cout << "FLOAT: " << ptr->data_float << std::endl;
    std::cout << std::endl;

    printTitle("Pointer Modifying");
    ptr->data_int = 5;
    ptr->data_string = "Hello World Modified";
    ptr->data_float = 42.42;

    std::cout << CYAN << "Pointer Data:" << RESET << std::endl;
    std::cout << "INT: " << ptr->data_int << std::endl;
    std::cout << "STRING: " << ptr->data_string << std::endl;
    std::cout << "FLOAT: " << ptr->data_float << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "Original Data (should be modified):" << RESET << std::endl;
    std::cout << "INT: " << original.data_int << std::endl;
    std::cout << "STRING: " << original.data_string << std::endl;
    std::cout << "FLOAT: " << original.data_float << std::endl;
    std::cout << std::endl;

    printTitle("Pointer Pointing to New Instance");
    Data newData = *ptr; // Copy original data to newData
    ptr = &newData; // Point ptr to newData
    ptr->data_int = 10;
    ptr->data_string = "New Data Instance";
    ptr->data_float = 99.99;
    std::cout << std::endl;
    std::cout << CYAN << "Pointer Data (after pointing to new instance):" << RESET << std::endl;
    std::cout << "INT: " << ptr->data_int << std::endl;
    std::cout << "STRING: " << ptr->data_string << std::endl;
    std::cout << "FLOAT: " << ptr->data_float << std::endl;
    std::cout << std::endl;
    std::cout << YELLOW << "Original Data (should remain unchanged):" << RESET << std::endl;
    std::cout << "INT: " << original.data_int << std::endl;
    std::cout << "STRING: " << original.data_string << std::endl;
    std::cout << "FLOAT: " << original.data_float << std::endl;
    std::cout << std::endl;

    printTitle("Null Pointer");
    Data* nullPtr = NULL;
    uintptr_t nullRaw = Serializer::serialize(nullPtr);
    std::cout << "Serialized null pointer value: " << nullRaw << std::endl;
    
    Data* dNull = Serializer::deserialize(nullRaw);
    if (dNull == NULL) {
        std::cout << GREEN << "SUCCESS! Nullptr == NULL" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE! Nullptr != NULL" << RESET << std::endl;
    }
    std::cout << std::endl;

    printTitle("Zero Value");
    Data* zeroPtr = Serializer::deserialize(0); 
    if (zeroPtr == NULL) {
        std::cout << GREEN << "SUCCESS! ZeroPtr == NULL" << RESET << std::endl;
    } else {
        std::cout << RED << "FAILURE! ZeroPtr != NULL" << RESET << std::endl;
    }

}

