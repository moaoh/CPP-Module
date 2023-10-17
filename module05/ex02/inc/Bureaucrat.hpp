#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat(const std::string str, int _grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat	&operator = (const Bureaucrat& rhs);
	~Bureaucrat();


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
	int			getGrade() const;

	void		signForm( AForm& aform );
	void		executeForm(AForm const & aform);
};

std::ostream &operator << (std::ostream& os, const Bureaucrat& other);

# endif
