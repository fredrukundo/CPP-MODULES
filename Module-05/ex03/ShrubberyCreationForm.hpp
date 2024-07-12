#ifndef SHRUBBERYCREACTIONFORM_HPP
#define SHRUBBERYCREACTIONFORM_HPP

#include "AForm.hpp"
#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

#include <iostream>
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	const	_target;
public:
	virtual void		execute(Bureaucrat const &executor) const;
	std::string const	&getTarget() const;

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &_target);
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();
};

#endif