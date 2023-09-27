#include "form.hpp"

Form::Form()
{
	this->name = "none";
	this->sign = false;
	this->signGrade
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// <bureaucrat> signed <form>
// <bureaucrat> couldn’t sign <form> because <reason>.
std::ostream &operator << (std::ostream& os, const Form& other)
{
	return os;
}
