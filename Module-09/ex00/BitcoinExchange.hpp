#pragma once

#include <iostream>
#include <stdexcept>
#include <map>
/*
    std::map:
        bcose 1. key-value pair storage
              2. sorted order
              3. unique key
*/
class BitcoinExchange {
    private:
        std::map<std::string, double> data;
        bool    isValidValue(const std::string &valueStr);
        bool    isValidDate(const std::string &dateStr);
        void    parseDB();
        void    parseInput(std::string const &fileName);
        void    calculateValue(std::string const &date, double const value);
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &);
        BitcoinExchange &operator=(BitcoinExchange const &);
        ~BitcoinExchange();

        class DBEmptyException : public std::exception {
            public:
                const char* what() const throw();
        };

        class DBFormatException : public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        static void putPrices(std::string const &fileName);
};