#pragma once

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<int> data;
        RPN();
        RPN( RPN const &);
        RPN &operator=(RPN const &);
        ~RPN();

        void    calc(std::string const &expression);
        void    process(char c);

        class RPNException : public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        static void calculate(std::string const &expression);
};