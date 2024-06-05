#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain const &brain);
        Brain &operator=(Brain const &other);
        ~Brain();
};
#endif