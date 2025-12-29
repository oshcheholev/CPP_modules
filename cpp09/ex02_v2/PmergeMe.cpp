// PmergeMe.cpp
#include "PmergeMe.hpp"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <time.h>

// Инициализация статических переменных
int PmergeMe::comparisons = 0;
bool PmergeMe::debug = false;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

// Генерация последовательности Якобсталя
std::vector<int> PmergeMe::generateJacobsthal(int n) {
    std::vector<int> jacob;
    if (n >= 1) jacob.push_back(1);
    if (n >= 2) jacob.push_back(3);
    
    for (int i = 2; ; i++) {
        int next = jacob[i-1] + 2 * jacob[i-2];
        if (next > n) break;
        jacob.push_back(next);
    }
    return jacob;
}

// Jacobsthal generator that returns a deque (avoids temporary vectors when using deque-based sort)
std::deque<int> PmergeMe::generateJacobsthalDeque(int n) {
    std::deque<int> jacob;
    if (n >= 1) jacob.push_back(1);
    if (n >= 2) jacob.push_back(3);

    for (int i = 2; ; i++) {
        int next = jacob[i-1] + 2 * jacob[i-2];
        if (next > n) break;
        jacob.push_back(next);
    }
    return jacob;
}

// Theoretical helpers

static long long informationLowerBoundComparisons(int n) {
    if (n <= 1) return 0;
    double sum = 0.0;
    for (int i = 2; i <= n; ++i) sum += std::log(static_cast<double>(i)) / std::log(2.0);
    return static_cast<long long>(std::ceil(sum));
}


// Бинарный поиск (overloads for vector and deque)
int PmergeMe::binarySearch(const std::vector<int>& container, int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (debug) {
            std::cout << "Comparison " << comparisons << " (binarySearch): compare container[" << mid << "]="
                      << container[mid] << " with " << value << " in [" << left << "," << right << "]" << std::endl;
        }

        if (container[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int PmergeMe::binarySearch(const std::deque<int>& container, int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (debug) {
            std::cout << "Comparison " << comparisons << " (binarySearch): compare container[" << mid << "]="
                      << container[mid] << " with " << value << " in [" << left << "," << right << "]" << std::endl;
        }

        if (container[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Вспомогательная функция: сортировка вектора
// helper: linear find insert position with counting and debug
// (removed generic linear findInsertPos; using binaryFindInsertPos* helpers)

// templated binary search to find insertion position (lower_bound) with counting and debug
template<typename Container>
static int binaryFindInsertPos(const Container& cont, const typename Container::value_type& value, int limit, int &comparisons, bool debug, int depth = 0, const std::string& tag = "") {
    int left = 0;
    int right = limit - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (debug) {
            std::cout << std::string(depth * 2, ' ') << "Comparison " << comparisons
                      << " (" << tag << "): cont[" << mid << "]=" << cont[mid]
                      << " < value=" << value << " -> ";
        }
        if (cont[mid] < value) {
            if (debug) std::cout << "true" << std::endl;
            left = mid + 1;
        } else {
            if (debug) std::cout << "false" << std::endl;
            right = mid - 1;
        }
    }
    return left;
}

// Vector-specific implementation moved to `PmergeMe_vector.cpp`
// (binaryFindInsertPosVector, sortVectorRecursive, and PmergeMe::fordJohnsonSort for vector)

// Deque-specific implementation moved to `PmergeMe_deque.cpp`
// (binaryFindInsertPosDeque, sortDequeRecursive, and PmergeMe::fordJohnsonSort for deque)

// Специализации для vector и deque
double PmergeMe::sort(std::vector<int>& vec, bool debugMode) {
    debug = debugMode;
    comparisons = 0;
    if (debugMode) {
        int n = (int)vec.size();
        long long lb = informationLowerBoundComparisons(n);
        std::cout << "Theoretical lower bound for " << n << " elements: " << lb << std::endl;
    }
    struct timespec ts_start, ts_end;
    clock_gettime(CLOCK_MONOTONIC, &ts_start);
    fordJohnsonSort(vec, 0, vec.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &ts_end);
	// std::cout << "Total comparisons: " << comparisons << std::endl;

    double time = (ts_end.tv_sec - ts_start.tv_sec) * 1e6 + (ts_end.tv_nsec - ts_start.tv_nsec) / 1e3;
    return time;
}

double PmergeMe::sort(std::deque<int>& deq, bool debugMode) {
    debug = debugMode;
    comparisons = 0;
    if (debugMode) {
        int n = (int)deq.size();
        long long lb = informationLowerBoundComparisons(n);
        std::cout << "Theoretical lower bound for " << n << " elements: " << lb << std::endl;
    }
    struct timespec ts_start, ts_end;
    clock_gettime(CLOCK_MONOTONIC, &ts_start);
    fordJohnsonSort(deq, 0, deq.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &ts_end);

    double time = (ts_end.tv_sec - ts_start.tv_sec) * 1e6 + (ts_end.tv_nsec - ts_start.tv_nsec) / 1e3;
    return time;
}

// Утилиты
template<typename T>
void PmergeMe::print(const T& container, const std::string& msg) {
    if (!msg.empty()) std::cout << msg << ": ";
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i < container.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

template<typename T>
bool PmergeMe::isSorted(const T& container) {
    for (size_t i = 1; i < container.size(); i++) {
        if (container[i] < container[i - 1]) {
            std::cerr << "Not sorted at position " << i 
                      << ": " << container[i-1] << " > " << container[i] << std::endl;
            return false;
        }
    }
    return true;
}

int PmergeMe::getComparisons() {
    return comparisons;
}

// Явные инстанциации
// (explicit template instantiations for binarySearch removed — using non-template overloads)
// (removed explicit template instantiations for fordJohnsonSort - using non-template overloads)
template void PmergeMe::print<std::vector<int> >(
    const std::vector<int>&, const std::string&);
template void PmergeMe::print<std::deque<int> >(
    const std::deque<int>&, const std::string&);
template bool PmergeMe::isSorted<std::vector<int> >(
    const std::vector<int>&);
template bool PmergeMe::isSorted<std::deque<int> >(
    const std::deque<int>&);