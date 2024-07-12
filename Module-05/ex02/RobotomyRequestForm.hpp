#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private:
	std::string	const	_target;
public:
	virtual void		execute(Bureaucrat const &executor) const;
	std::string const	&getTarget() const;

	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &form);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);
	~RobotomyRequestForm();
};

#endif