#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int main()
{
	const int nb_animals = 2;
	const Animal *animals[nb_animals];

	for (int i = 0; i < nb_animals; i++)
	{
		if (i < nb_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < nb_animals; i++)
		animals[i]->makeSound();

	std::cout << std::endl;

	for (int i = 0; i < nb_animals; i++)
		delete animals[i];

	std::cout << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	return 0;
}