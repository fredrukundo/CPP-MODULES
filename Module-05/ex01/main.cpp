#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	a("fred", 50);
		Form		form0("A99", 60, 60);
		Form		form1("Wrong_f", 49, 49);
		a.signForm(form0);
		a.signForm(form0);
		a.signForm(form1);
		Form		form2("Wrong0_", 0, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}