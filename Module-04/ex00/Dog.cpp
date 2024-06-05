#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor is called" << std::endl;
}

Dog::Dog(const Dog &cpy)
{
    *this = cpy;
    std::cout << "Dog copy constructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor is called" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::makeSound() const{
    std::cout << "Dog bark bark" << std::endl;
}