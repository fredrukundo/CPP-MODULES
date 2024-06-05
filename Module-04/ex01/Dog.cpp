#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
    this->brain = new Brain(*cpy.brain);
    std::cout << "Dog copy constructor  called" << std::endl;
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
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog bark bark" << std::endl;
}