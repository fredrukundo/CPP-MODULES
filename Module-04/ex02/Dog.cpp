#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog Default constructor is called" << std::endl;
}

Dog::Dog(const Dog &cpy)
{
    this->brain = NULL;
    *this = cpy;
    std::cout << "Dog copy constructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this->brain)
        delete (this->brain);
    this->brain = new Brain(*other.brain);
    this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog bark bark" << std::endl;
}