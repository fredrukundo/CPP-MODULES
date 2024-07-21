#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	/* Create a form with grade too high */
	{
		try
		{
			Form form0("FM1", 0, 100);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";

	/* Create form and sign it without exceptions */
	{
		try
		{
			Bureaucrat fred("Duke", 20);
			Form form("FM2", 25, 45);
			std::cout << fred << std::endl;
			std::cout << form << std::endl;
			fred.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	/* Create form and try to sign it but the grade is not enough */
	{
		try
		{
			Bureaucrat paul("Clem", 35);
			Form form1("FM3", 20, 45);
			std::cout << paul << std::endl;
			std::cout << form1 << std::endl;
			paul.signForm(form1);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}