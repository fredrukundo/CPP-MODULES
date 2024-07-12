#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
   private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			execGrade;
	public:
		Form();
		Form(std::string const name, int const signGrade, int const execGrade);
		Form( Form const &cpy);
		~Form();
		Form &operator=(Form const &src);

		std::string const &getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);
		int					verifyGrade(int const grade);

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

		class FormSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};
std::ostream	&operator<<(std::ostream &o, Form const &src);

#endif