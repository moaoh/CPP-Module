#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : \
	AForm("Robotomy Request", _target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) {}

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm& rhs) {
	this->AForm::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		this->checkExecutor(executor);
		std::cout << this->getTarget() + " has been robotomized" << std::endl;
		int number = (rand() % 2);
		std::cout << "drilling~ drilling~ drrrrrrrr" << std::endl;
		if (number) {
			std::cout << this->getName() + " succeeded in becoming a robot" << std::endl;
		}
		else {
			std::cout << this->getName() + " failed to becoming a robot" << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cerr << "[RobotomyRequestForm] error : " << e.what() << '\n';
	}
}

AForm *RobotomyRequestForm::create(std::string const& target) {
	return new RobotomyRequestForm(target);
}
