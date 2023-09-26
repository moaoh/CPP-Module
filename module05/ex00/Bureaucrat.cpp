#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "none";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string str)
{
	this->name = str;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string str, const int _grade)
{
	this->name = str;
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	this->name = other.name;
	this->grade = other.grade;
}

Bureaucrat	&Bureaucrat::operator = ( const Bureaucrat& other )
{
	this->name = other.name;
	this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::upGrade()
{
	setGrade(this->grade - 1);
}

void Bureaucrat::downGrade()
{
	setGrade(this->grade + 1);
}


void Bureaucrat::setGrade(int const _grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (150 < _grade)
		throw Bureaucrat::GradeTooLowException();
	this->grade = _grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int			Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream &operator << (std::ostream& os, const Bureaucrat& other)
{
	return os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
}
