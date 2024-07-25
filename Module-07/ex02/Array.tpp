#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->arr = new T[0];
    printf("create this->arr = %p\n", this->arr);
    this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int const n)
{
    this->arr = new T[n];

    printf("create this->arr = %p\n", this->arr);

    this->_size = n;
}

template <typename T>
Array<T>::Array(Array const &cpy)
{
    *this = cpy;
}

template <typename T>
Array<T>    &Array<T>::operator=(Array const &src)
{
    this->_size = src._size;
    printf("delete this->arr = %p\n", this->arr);
    delete [] this->arr;
    this->arr = new T[this->_size];
    printf("create this->arr = %p\n", this->arr);
    for ( unsigned int i = 0; i < this->_size; i++)
        this->arr[i] = src.arr[i];
    return *this;
}

template <typename T>
T   &Array<T>::operator[](unsigned int i)
{
    if ( i < 0 || i >= this->_size)
        throw std::out_of_range("Index is out of bounds");
    return this->arr[i];
}

template <typename T>
T   &Array<T>::operator[](unsigned int i) const
{
    if ( i < 0 || i >= this->_size)
        throw std::out_of_range("Index is out of bounds");
    return this->arr[i];
}

template <typename T>
Array<T>::~Array()
{
    printf("delete this->arr = %p\n", this->arr);
	delete [] this->arr;
	this->_size = 0;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}