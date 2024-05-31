#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	void	highFiveGuys(void) const;

	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &frag);
	FragTrap	&operator=(FragTrap const &other);
	~FragTrap();
};
#endif