#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &other);
        ~Dog();
        std::string getType() const;
        void makeSound() const;
};
#endif