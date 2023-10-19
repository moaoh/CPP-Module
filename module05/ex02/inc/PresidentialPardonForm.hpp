#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
public:
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm	&operator = (const PresidentialPardonForm& rhs);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;
};

#endif
