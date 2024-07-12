#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("(default)"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.getName())
{
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	this->grade = src.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

std::string	const	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this <<" couldn't sign "<<form << " because "<< e.what() << '\n';
	}
	
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << *this << " did not execute " << form << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src)
{
	return o << src.getName() << ", bureaucrat grade " << src.getGrade();
}