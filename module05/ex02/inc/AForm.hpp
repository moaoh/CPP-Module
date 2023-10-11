#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool							isSign;
	const int					signGrade;
	const int					executeGrade;

public:
	Form(const std::string str, const int _signGrade, const int _executeGrade);
	Form(const Form& src);
	Form	&operator = (const Form& rhs);
	~Form();

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	std::string	getName() const;
	bool				getIsSign() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void	beSigned( const Bureaucrat& bure );
};

std::ostream &operator << (std::ostream& os, const Form& other);

#endif
