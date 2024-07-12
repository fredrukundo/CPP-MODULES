#include "Form.hpp"

Form::Form() : name("(default)"), isSigned(false), signGrade(150), execGrade(150) 
{}

Form::Form(std::string const name, int const signGrade, int const execGrade) : name(name), isSigned(false), signGrade(this->verifyGrade(signGrade)), execGrade(this->verifyGrade(execGrade))
{}
Form::Form(Form const &form) : name(form.getName()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
    *this = form;
}

Form    &Form::operator=(Form const &src)
{
    this->isSigned = src.isSigned;
    return *this;
}

Form::~Form(){}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Form::FormSignedException::what() const throw()
{
	return "Form already signed!";
}

std::string const   &Form::getName() const
{
    return this->name;
}

bool    Form::getIsSigned() const 
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExecGrade() const
{
    return this->execGrade;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->isSigned)
		throw Form::FormSignedException();
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

int Form::verifyGrade(int const grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
    return grade;
}

std::ostream    &operator<<(std::ostream &o, Form const &src)
{
    return o << src.getName() << " signed: " << src.getIsSigned() << ", grade to sign " << src.getSignGrade() << ", grade to execute: " << src.getExecGrade();
}