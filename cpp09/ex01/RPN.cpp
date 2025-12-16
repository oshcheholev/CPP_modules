#include "RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>
#include <climits>

RPN::RPN() {}
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->listStack = other.listStack;
	}
	return *this;
}
RPN::RPN(const RPN &other) {
	*this = other;
}

// static void checkOverflow(double value) {
// 	if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN)) {
// 		throw std::overflow_error("Error: integer overflow");
// 	}
// }

static bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::reversePolishNotation(const std::string& str)
{
    // Clear stack
    while (!listStack.empty())
        listStack.pop();

    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {

            if (listStack.size() < 2)
                throw std::runtime_error("Error");

            int b = listStack.top(); listStack.pop();
            int a = listStack.top(); listStack.pop();

            long tmp;

            if (token == "+")
                tmp = static_cast<long>(a) + static_cast<long>(b);
            else if (token == "-")
                tmp = static_cast<long>(a) - static_cast<long>(b);
            else if (token == "*")
                tmp = static_cast<long>(a) * static_cast<long>(b);
            else {
                if (b == 0)
                    throw std::runtime_error("Error");
                tmp = a / b;
            }

//            checkOverflow(tmp);
            listStack.push(static_cast<int>(tmp));
        }
        else {
            if (token.length() != 1 ||
                !std::isdigit(static_cast<unsigned char>(token[0])))
                throw std::runtime_error("Error");

            listStack.push(token[0] - '0');
        }
    }

    if (listStack.size() != 1)
        throw std::runtime_error("Error");

    return listStack.top();
}
