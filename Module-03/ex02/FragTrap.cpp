#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor for the " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &clap)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = clap;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

void	FragTrap::highFiveGuys(void) const
{
	std::cout << "FragTrap " << this->name << " requesting for a high fives!" << std::endl;
}
