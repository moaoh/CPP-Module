#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string _name, std::string _target) :
	AForm(_name, _target, 25, 5) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		this->checkExecutor(executor);
		std::ofstream outFile(this->getTarget() + "_shrubbery");
		if (!outFile.is_open()) {
			return throw std::runtime_error("error: not open file\n");
		}
		outFile << ASCII_TREE_ART << std::endl;
		outFile.close();
		std::cout << "Create " + this->getTarget() + "_shrubbery" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "[ShrubberyCreationForm] error : " << e.what() << '\n';
	}
}
