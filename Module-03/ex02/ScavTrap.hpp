#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		void	guardGate() const;
		void	attack( const std::string& target);

		ScavTrap();
		ScavTrap( std::string name);
		ScavTrap( const ScavTrap& cpy);
		ScavTrap &operator=( const ScavTrap &other);
		~ScavTrap();

};
#endif