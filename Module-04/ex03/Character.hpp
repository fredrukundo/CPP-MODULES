#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{

private:
	AMateria	*inventory[4];
	std::string	name;

public:
	Character();
	Character(std::string const &name);
	Character(Character const &cpy);
	Character	&operator=(Character const &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif