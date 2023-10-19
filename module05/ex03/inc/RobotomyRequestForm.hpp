#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm	&operator = (const RobotomyRequestForm& rhs);
	virtual ~RobotomyRequestForm();

	static AForm *create(std::string const& target);

private:
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
