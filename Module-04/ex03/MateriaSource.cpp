#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

MateriaSource::MateriaSource(MateriaSource const &cpy)
{
	*this = cpy;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 3; i >= 0; i--)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	}
	return 0;
}
