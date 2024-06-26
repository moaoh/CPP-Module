#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string str, int _grade) : name(str) {
	setGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
	setGrade(other.grade);
}

Bureaucrat	&Bureaucrat::operator = ( const Bureaucrat& other ) {
	setGrade(other.grade);
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: Grade too low");
}

void Bureaucrat::upGrade() {
	setGrade(this->grade - 1);
}

void Bureaucrat::downGrade() {
	setGrade(this->grade + 1);
}


void Bureaucrat::setGrade(int const _grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (150 < _grade)
		throw Bureaucrat::GradeTooLowException();
	this->grade = _grade;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int			Bureaucrat::getGrade() const {
	return this->grade;
}

// <bureaucrat> signed <form>
// <bureaucrat> couldn’t sign <form> because <reason>.
void		Bureaucrat::signForm( AForm& aform ) {
	try {
		aform.beSigned(*this);
		std::cout << "[" << this->getName() << "] signed [" << aform.getName() << "]" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "[" << this->getName() << "] couldn’t sign [" \
							<< aform.getName() << "] because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const & aform) {
	try {
		aform.checkIsSign();
		aform.checkExecutor(*this);
		aform.execute(*this);
		std::cout << this->getName() << " executed " << aform.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "[executeForm] error :" << e.what() << '\n';
	}
}

std::ostream &operator << (std::ostream& os, const Bureaucrat& other) {
	return os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
}
