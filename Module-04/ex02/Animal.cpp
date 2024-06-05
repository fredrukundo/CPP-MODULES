#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy contructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other)
{
    this->type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}