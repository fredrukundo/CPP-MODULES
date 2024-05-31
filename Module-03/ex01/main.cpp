#include "ScavTrap.hpp"

int main()
{
    ScavTrap sv1;
    
    ScavTrap sv2("fred");
    ClapTrap ct("clap1");

    ScavTrap sv3(sv1);

    ct.attack("clap");
    sv1.attack("scav");

    sv1.beRepaired(12);
    sv1.takeDamage(60);
    
    ct.takeDamage(40);
    sv2.guardGate();

    return (0);
}