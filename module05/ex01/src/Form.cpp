#include "Form.hpp"

Form::Form(const std::string str, const int _signGrade, const int _executeGrade) :
		name(str),
		signGrade(_signGrade),
		executeGrade(_executeGrade) {}

Form::Form(const Form& other) :
			name(other.name),
			signGrade(other.signGrade),
			executeGrade(other.executeGrade) {
		this->isSign = other.isSign;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form: Grade too low");
}

std::string		Form::getName() const {
	return this->name;
}
bool					Form::getIsSign() const {
	return this->isSign;
}
int						Form::getSignGrade() const {
	return this->signGrade;
}
int						Form::getExecuteGrade() const {
	return this->executeGrade;
}

void	Form::beSigned( const Bureaucrat& bure ) {
	if (bure.getGrade() > this->getExecuteGrade()) {
		return throw Form::GradeTooLowException();
	}
	this->isSign = true;
}

std::ostream &operator << (std::ostream& os, const Form& other) {
	return os << "===== Form =====" << "\n" \
						<< "name : " << other.getName() << "\n" \
						<< "isSign : " << other.getIsSign() << "\n" \
						<< "signGrade : " << other.getSignGrade() << "\n" \
						<< "executeGrade : " << other.getExecuteGrade() << "\n" \
						<< "================" << std::endl;
}
