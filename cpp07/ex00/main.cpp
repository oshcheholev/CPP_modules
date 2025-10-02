#include "whatever.cpp"
#include "utils.hpp"
#include <string>
#include <iostream>

int main() {

printTitle("Test from the Subject");

int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


printTitle("More tests (floats and strings)");
float e = 1.5f;
float f = 2.5f;
std::cout << "before e = " << e << ", f = " << f << std::endl;
::swap(e, f);
std::cout << "after e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
std::string str1 = "Drucilla";
std::string str2 = "Eduardo";
std::cout << "before str1 = " << str1 << ", str2 = "<< str2 << std::endl;
::swap(str1, str2);
std::cout << "after str1 = " << str1 << ", str2 = "<< str2 << std::endl;
std::cout << "min( str1, str2 ) = " << ::min(str1, str2) << std::endl;
std::cout << "max( str1, str2 ) = " << ::max(str1, str2) << std::endl;

// int k = 42;
// float l = 3.14f;
// To show that we cannot swap and compare different types
// ::swap(k, l);
// std::cout << "min( k, l ) = " << ::min(k, l) << std::endl;
// std::cout << "max( k, l ) = " << ::max(k, l) << std::endl;	

return 0;

}