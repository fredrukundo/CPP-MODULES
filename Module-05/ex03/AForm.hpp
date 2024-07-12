#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
   private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			execGrade;
	public:
		AForm();
		AForm(std::string const name, int const signGrade, int const execGrade);
		AForm( AForm const &cpy);
		~AForm();
		AForm &operator=(AForm const &src);

		std::string const &getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);
		int					verifyGrade(int const grade);
        virtual void        execute(Bureaucrat const &executor) const = 0;
        void                checkExecution(Bureaucrat const &executor) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};
std::ostream	&operator<<(std::ostream &o, AForm const &src);

#endif