#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

class PmergeMe {
private:
    static int comparisons;
    static bool debug;
    
    // Вспомогательные функции (explicit overloads for each container)
    static void fordJohnsonSort(std::vector<int>& container, int left, int right);
    static void fordJohnsonSort(std::deque<int>& container, int left, int right);

    static int binarySearch(const std::vector<int>& container, int value, int left, int right);
    static int binarySearch(const std::deque<int>& container, int value, int left, int right);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
    ~PmergeMe();
    
    // Основные методы
    static double sort(std::vector<int>& vec, bool debugMode = false);
    static double sort(std::deque<int>& deq, bool debugMode = false);
    static std::vector<int> generateJacobsthal(int n);
    static std::deque<int> generateJacobsthalDeque(int n);
    
    // Утилиты
    template<typename T>
    static void print(const T& container, const std::string& msg);
    
    template<typename T>
    static bool isSorted(const T& container);
    
    static int getComparisons();
};

#endif