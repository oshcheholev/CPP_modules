#include "whatever.hpp"
//swap
template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

//min
template <typename T>
const T& min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

//max
template <typename T>
const T& max(const T &a, const T &b) {
    return (a > b) ? a : b;
}