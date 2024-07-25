#pragma once

template <typename T>
class Array {
    private:
        T               *arr;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int const n);
        Array(Array const &cpy);
        Array   &operator=(Array const &src);
        T       &operator[](unsigned int i);
        ~Array();
        unsigned int	size() const;
};

#include "Array.tpp"