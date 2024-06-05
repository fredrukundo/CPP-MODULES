#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
}
AMateria::~AMateria()
{
}
AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria( const AMateria &cpy) : type(cpy.type)
{
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	this->type = other.getType();
	return (*this);
}

std::string	const	&AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used at " << target.getName() << " *" << std::endl;
}


