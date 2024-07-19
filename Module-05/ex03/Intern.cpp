#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern	&Intern::operator=(Intern const &src)
{
	if (&src != this)
		return *this;
	return *this;
}

Intern::~Intern() {}

const char*	Intern::FormNotFound::what() const throw()
{
	return "Form not found";
}

AForm	*Intern::makeForm(std::string const name, std::string const target)
{
	AForm		*form;
	std::string	lists[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	try
	{	
		for (int i = 0; i < 3; i++)
		{
			if (name == lists[i])
			{
				switch (i)
				{
					case 0:
						form = new ShrubberyCreationForm(target);
						break ;
					case 1:
						form = new RobotomyRequestForm(target);
						break ;
					case 2:
						form = new PresidentialPardonForm(target);
						break ;
					default:
						form = NULL;
						break ;
				}
				std::cout << "Intern creates " << *form << "." << std::endl;
				return form;
			}
		}
		throw Intern::FormNotFound();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}