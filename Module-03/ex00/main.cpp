#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	ct1;
	ClapTrap	ct2("Duke");
	ClapTrap	ct3(ct1);
	ClapTrap	ct4;
	
	ct4 = ct2;
	ct1.attack("Target1");
	ct2.takeDamage(0);
	ct4.takeDamage(0);
	ct3.beRepaired(-6);
	ct1.beRepaired(6);
	ct4.attack("Target2");
	ct1.takeDamage(0);
	ct3.takeDamage(0);
	return (0);
}