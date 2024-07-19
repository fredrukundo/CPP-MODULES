#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Intern random;
		AForm *form;

		form = random.makeForm("shrubbery creation", "Bender");
		delete form;
		form = random.makeForm("robotomy request", "Bender");
		delete form;
		form = random.makeForm("presidential pardon", "Bender");
		delete form;
		form = random.makeForm("bad form", "Bender");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}