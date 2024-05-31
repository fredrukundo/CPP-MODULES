#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap ct("clap1");
    ScavTrap st("fred");
    FragTrap ft("duke");

    ct.attack("clap");
    st.attack("scav");
    
    ct.takeDamage(40);
    st.guardGate();
    ft.attack("target");
    ft.highFiveGuys();

    return (0);
}