#include "../inc/AForm.hpp"

AForm::AForm(const std::string _name,
		const std::string _target,
		const int _signGrade,
		const int _executeGrade) :
		name(_name),
		target(_target),
		signGrade(_signGrade),
		executeGrade(_executeGrade) {
	this->isSign = false;
}

AForm::AForm(const AForm& other) :
		name(other.getName()),
		signGrade(other.getSignGrade()),
		executeGrade(other.getExecuteGrade()) {
	this->isSign = other.getIsSign();
}

AForm	&AForm::operator = (const AForm& rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->isSign = rhs.getIsSign();
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm: Grade too low");
}

const char* AForm::UnsignedForm::what() const throw() {
	return ("Unsigned Form");
}

std::string		AForm::getName() const {
	return this->name;
}
std::string		AForm::getTarget() const {
	return this->target;
}
bool					AForm::getIsSign() const {
	return this->isSign;
}
int						AForm::getSignGrade() const {
	return this->signGrade;
}
int						AForm::getExecuteGrade() const {
	return this->executeGrade;
}

void	AForm::beSigned( const Bureaucrat& bure ) {
	if (bure.getGrade() > this->getExecuteGrade()) {
		return throw AForm::GradeTooLowException();
	}
	this->isSign = true;
}

void		AForm::checkIsSign() const {
	if (this->getIsSign() == false) {
		throw AForm::UnsignedForm();
	}
}

void		AForm::checkExecutor(Bureaucrat const & executor) const {
	if (this->getExecuteGrade() < executor.getGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream &operator << (std::ostream& os, const AForm& other) {
	return os << "===== AForm =====" << "\n" \
						<< "name : " << other.getName() << "\n" \
						<< "isSign : " << other.getIsSign() << "\n" \
						<< "signGrade : " << other.getSignGrade() << "\n" \
						<< "executeGrade : " << other.getExecuteGrade() << "\n" \
						<< "================" << std::endl;
}
