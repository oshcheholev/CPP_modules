#ifndef RPN_HPP
#define RPN_HPP


#include <stack>
#include <string>
#include <list>


class RPN {
private:
	std::stack<long, std::list <long> > listStack;

public:
	RPN();
	~RPN();
	RPN &operator=(const RPN &other);
	RPN(const RPN &other);

	
	double reversePolishNotation(const std::string& str);
};


#endif // RPN_HPP