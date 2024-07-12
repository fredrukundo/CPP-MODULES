#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat {
private:
	std::string	const	name;
	int				grade;
public:
   int				getGrade() const;
	std::string	const &getName() const;
	void					incrementGrade();
	void					decrementGrade();
	void					signForm(AForm &form);
	void					executeForm(AForm const &form);

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

};
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src);

#endif