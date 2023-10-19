#include "../inc/Form.hpp"

Form::Form(const std::string _name, const int _signGrade, const int _executeGrade) :
		name(_name),
		signGrade(_signGrade),
		executeGrade(_executeGrade) {
			this->isSign = false;
}

Form::Form(const Form& src) :
			name(src.name),
			signGrade(src.signGrade),
			executeGrade(src.executeGrade) {
		this->isSign = src.isSign;
}

Form	&Form::operator = (const Form& rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->isSign = rhs.getIsSign();
	return (*this);
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
