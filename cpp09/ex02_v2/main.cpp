// main.cpp (остается без изменений)
#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>

static void printUsage() {
    std::cout << "Usage: ./PmergeMe <numbers...> [--debug]" << std::endl;
    std::cout << "Example: ./PmergeMe 3 1 4 1 5 9" << std::endl;
    std::cout << "         ./PmergeMe 3 1 4 1 5 9 --debug" << std::endl;
}

static bool isNumber(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printUsage();
        return 1;
    }
    
    bool debug = false;
    std::vector<int> numbers;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "--debug") {
            debug = true;
        } else if (isNumber(arg)) {
            int num = atoi(arg.c_str());
            if (num <= 0) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            numbers.push_back(num);
        } else {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    
    if (numbers.empty()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // Проверка на дубликаты — запрещаем повторяющиеся значения
    {
        std::vector<int> tmp = numbers;
        std::sort(tmp.begin(), tmp.end());
        for (size_t i = 1; i < tmp.size(); ++i) {
            if (tmp[i] == tmp[i - 1]) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
    }
    
    // Выводим исходный массив (compact)
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    // Создаем копии для сортировки
    std::vector<int> vec = numbers;
    std::deque<int> deq(numbers.begin(), numbers.end());
    
    // Сортируем вектор и дек — collect timings, print them after 'After:'
    double timeVec = PmergeMe::sort(vec, debug);
    double timeDeq = PmergeMe::sort(deq, debug);

    // Выводим результат (compact)
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    // Print timing results
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
    return 0;
}