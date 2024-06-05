#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &WrongAnimal1);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
};
#endif