#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	std::string name;
	int			grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string str);
	Bureaucrat(const std::string str, const int _grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat	&operator = ( const Bureaucrat& other );

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

	void upGrade();
	void downGrade();
	void setGrade(int _grade);

	std::string getName() const;
	int			getGrade() const;
};

std::ostream &operator << (std::ostream& os, const Bureaucrat& other);

# endif
