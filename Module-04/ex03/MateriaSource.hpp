#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria	*inventory[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &cpy);
	MateriaSource	&operator=(MateriaSource const &other);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const &type);
};

#endif