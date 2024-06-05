#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy)
{
    this->brain = NULL;//check a copy constructor??
    *this = cpy;
    std::cout << "Cat copy Constructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    this->type = other.type;
    if (this->brain)
		delete (this->brain);
	this->brain = new Brain(*(other.brain));
	return (*this);
}
Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor is called" << std::endl;
}

void Cat::makeSound()const {
    std::cout << "Cat Meow meow" << std::endl;
}
