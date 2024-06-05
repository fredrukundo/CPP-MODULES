#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &cpy) : AMateria(cpy.getType())
{
	*this = cpy;
}

Ice	&Ice::operator=(Ice const &other)
{
	this->type = other.getType();
	return (*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria	*cloned = new Ice(*this);
	return (cloned);
}
