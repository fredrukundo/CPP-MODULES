#pragma once

#include <iostream>
#include <string.h>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>(){};
        MutantStack(MutantStack const &src) : std::stack<T>(src)
        {
            *this = src;
        }
        MutantStack &operator=(MutantStack const &src){
            std::stack<T>::operator=(src);
            return *this;
        }
        ~MutantStack(){}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin(void)
        {
            return this->c.begin();
        }
        iterator    end(void)
        {
            return this->c.end();
        }
};