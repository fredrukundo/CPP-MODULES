#pragma once

#include <iostream>

template <typename T>
void    iter( T *arr, size_t size, void (*f)(T &) )
{
    for ( size_t i = 0; i < size; i++)
        f(arr[i]);
}
//for handling the const
template <typename T>
void    iter( T *arr, size_t size, void (*f)(const T &) )
{
    for ( size_t i = 0; i < size; i++)
        f(arr[i]);
}

// template <typename T>
// void print( T &i) {
//     std::cout << i << std::endl;
// }