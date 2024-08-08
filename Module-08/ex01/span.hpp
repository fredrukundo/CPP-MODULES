#pragma once

#include <stdexcept>
#include <iostream>
#include <vector>

class Span {
    private:
        unsigned int    n;
        std::vector <int> _span;
    public:
        Span();
        Span( unsigned int n);
        Span(Span const &cpy);
        Span    &operator=(Span const &src);
        ~Span();

        void            addNumber(int nbr);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        void            fill( std::vector<int>::iterator begin, std::vector<int>::iterator end );

        class SpanFullException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};