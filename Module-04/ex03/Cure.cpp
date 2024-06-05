#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &cpy) : AMateria(cpy.getType())
{
	*this = cpy;
}

Cure	&Cure::operator=(Cure const &other)
{
	this->type = other.getType();
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria	*cloned = new Cure(*this);
	return (cloned);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
