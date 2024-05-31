#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor for the " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = cpy;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->name << " is in the Gate keeper mode" << std::endl;
}

void    ScavTrap::attack( const std::string& target)
{
	if (this->energyPoints && this->hitPoints )
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}
