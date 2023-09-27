#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	std::string name;
	bool		sign;
	int			signGrade;
public:
	Form();
	Form(const std::string str);
	Form(const Form& other);
	~Form();

	Form	&operator = ( const Form& other );

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	beSigned( const Bureaucrat& bure );
};

std::ostream &operator << (std::ostream& os, const Form& other);

#endif
