#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const &){}
RPN &RPN::operator=(RPN const &)
{
    return *this;
}
RPN::~RPN() {};

const char* RPN::RPNException::what() const throw()
{
    return "Error";
}

void    RPN::process(char c)
{
    int a;
    int b;

    if (this->data.size() < 2)
        throw RPN::RPNException();
    a = this->data.top();
    this->data.pop();
    b = this->data.top();
    this->data.pop();
    switch (c)
    {
    case '*':
        this->data.push(a * b);
        break;
    case '+':
        this->data.push(a + b);
        break;
    case '-':
        this->data.push(b - a);
        break;
    case '/':
        if (a == 0)
            throw RPN::RPNException();
        this->data.push(b / a);
        break;
    
    default:
        throw RPN::RPNException();
    }
}

void    RPN::evaluateExpression(std::string const &expression)
{
    std::string operations = "*/-+";
    
    for (size_t i = 0; i < expression.size(); i++)
	{
		size_t	pos = operations.find(expression[i], 0);
		if (!isdigit(expression[i]) && pos == std::string::npos && expression[i] != ' ')
			throw	RPN::RPNException();
		else if (isdigit(expression[i]) && expression[i + 1] == ' ')
			this->data.push(expression[i] - '0');
		else if (isdigit(expression[i]))
			throw	RPN::RPNException();
		else if (expression[i] == ' ')
			continue ;
		else if (expression[i + 1] == ' ' || !expression[i + 1])
			this->process(expression[i]);
		else
			throw RPN::RPNException();
	}
	if (this->data.size() != 1)
		throw RPN::RPNException();
	std::cout << this->data.top() << std::endl;
}

void    RPN::calculate(std::string const &expression )
{
    RPN obj;

    try
    {
        obj.evaluateExpression(expression);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}