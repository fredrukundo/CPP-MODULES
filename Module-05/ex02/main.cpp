#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm	shrubbery("Home");
		RobotomyRequestForm		robotomy("fred");
		PresidentialPardonForm	president("paul");
		Bureaucrat				duke("mike", 1);
		Bureaucrat				juru("steve", 144);

		duke.executeForm(shrubbery);
		duke.signForm(shrubbery);
		duke.signForm(robotomy);
		duke.signForm(president);
		duke.executeForm(shrubbery);
		juru.executeForm(shrubbery);
		duke.executeForm(robotomy);
		juru.executeForm(robotomy);
		duke.executeForm(president);
		juru.executeForm(president);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}