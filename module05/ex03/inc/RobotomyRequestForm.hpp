#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
public:
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm	&operator = (const RobotomyRequestForm& rhs);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;
	static AForm *create(std::string const& target);
};

#endif
