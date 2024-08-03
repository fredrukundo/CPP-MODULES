#pragma once

#include <iostream>
#include <stdexcept>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> data;
        bool    checkValue(const std::string &valueStr);
        bool    checkDate(const std::string &dateStr);
        void    parseDB();
        void    putPrice(std::string const &date, double const value);
        void    parseInput(std::string const &fileName);
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