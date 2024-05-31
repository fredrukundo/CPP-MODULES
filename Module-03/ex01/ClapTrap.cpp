#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("David"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor for the " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}

	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints)
	{
		if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return;
		}
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
		if (this->hitPoints < (int)amount)
			amount = hitPoints;
		this->hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints && this->energyPoints)
	{
		if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return;
		}
		std::cout << "ClapTrap " << this->name << " gets " << amount << " hit points back!" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
}
