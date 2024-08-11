#pragma once

#include <iostream>
#include <stack>
/*
    Reverse Polish Notation is a postfix notation where operators come after their operands
    i used std::stack"
    bcose: 1.LIFO order :bcose in RPN the most recent operands are used first
           
*/
class RPN {
    private:
        std::stack<int> data;
        RPN();
        RPN( RPN const &);
        RPN &operator=(RPN const &);
        ~RPN();

        void    evaluateExpression(std::string const &expression);
        void    process(char c);

        class RPNException : public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        static void calculate(std::string const &expression);
};