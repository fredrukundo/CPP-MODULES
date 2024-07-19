#pragma once

#include <iostream>
#include <string>
#include <sstream>

enum e_type {
   STRING, 
   DOUBLE,
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter &operator=(const ScalarConverter& src);
        ~ScalarConverter();

    public:
        static void convert(std::string &str);
};