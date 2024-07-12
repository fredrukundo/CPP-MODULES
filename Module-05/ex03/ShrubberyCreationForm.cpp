#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("(default)")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form) : AForm("ShrubberyCreationForm", 145, 137), _target(form.getTarget()) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (&src != this)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	outfile;

	this->checkExecution(executor);
	outfile.open(this->_target + "_shrubbery");
	if (!outfile.is_open())
		throw std::runtime_error("Couldn't open file");
	outfile << TREE;
	outfile.close();
}