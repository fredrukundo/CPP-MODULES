#include "AForm.hpp"

AForm::AForm() : name("(default)"), isSigned(false), signGrade(150), execGrade(150) 
{}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) : name(name), isSigned(false), signGrade(this->verifyGrade(signGrade)), execGrade(this->verifyGrade(execGrade))
{}
AForm::AForm(AForm const &form) : name(form.getName()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
    *this = form;
}

AForm    &AForm::operator=(AForm const &src)
{
    this->isSigned = src.isSigned;
    return *this;
}

AForm::~AForm(){}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::FormSignedException::what() const throw()
{
	return "Form already signed";
}
const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed yet";
}

std::string const   &AForm::getName() const
{
    return this->name;
}

bool    AForm::getIsSigned() const 
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->isSigned)
		throw AForm::FormSignedException();
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

int AForm::verifyGrade(int const grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
    return grade;
}

void    AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (this->execGrade < executor.getGrade())
        throw AForm::GradeTooLowException();
}

std::ostream    &operator<<(std::ostream &o, AForm const &src)
{
    return o << src.getName() << " signed: " << src.getIsSigned() << ", grade to sign " << src.getSignGrade() << ", grade to execute: " << src.getExecGrade();
}