#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cstring>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int								grade;
public:
	Bureaucrat(const std::string str, int _grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat	&operator = ( const Bureaucrat& other );

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	void upGrade();
	void downGrade();
	void setGrade(int _grade);

	std::string getName() const;
	int					getGrade() const;

	void				signForm( Form& form );
};

std::ostream &operator << (std::ostream& os, const Bureaucrat& other);

# endif
