#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy)
{
    *this = cpy;
    std::cout << "Cat copy Constructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    this->type = other.type;
    return (*this);
}
Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}
void Cat::makeSound()const {
    std::cout << "Cat Meow meow" << std::endl;
}
