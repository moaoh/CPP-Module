#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(Intern const& src);
	Intern &operator = (Intern const& rhs);
	~Intern();

	class InvalidFormName : public std::exception
	{
	public:
		const char *what() const throw();
	};

	AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif
