#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal1);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
};
#endif