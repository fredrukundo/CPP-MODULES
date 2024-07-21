#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("(default)")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : AForm("RobotomyRequestForm", 72, 45), _target(form.getTarget()) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (&src != this)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkExecution(executor);
	int	success;
	srand((unsigned) time(NULL));
	success = rand() % 2;
	if (success)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;

}