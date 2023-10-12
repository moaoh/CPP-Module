#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
public:
	ShrubberyCreationForm(std::string _name, std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm	&operator = (const ShrubberyCreationForm& rhs);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;
};

#define ASCII_TREE_ART "\
          .     .  .      +     .      .          . \n\
     .       .      .     #       .           . \n\
        .      .         ###            .      .      . \n\
      .      .   \"#:. .:##\"##:. .:#\"  .      . \n\
          .      . \"####\"###\"####\"  . \n\
       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       . \n\
  .             \"#########\"#########\"        .        . \n\
        .    \"#:.  \"####\"###\"####\"  .:#\"   .       . \n\
     .     .  \"#######\"\"##\"##\"\"#######\"                  . \n\
                .\"##\"#####\"#####\"##\"           .      . \n\
    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     . \n\
      .     \"#######\"##\"#####\"##\"#######\"      .     . \n\
    .    .     \"#####\"\"#######\"\"#####\"    .      . \n\
            .     \"      000      \"    .     . \n\
       .         .   .   000     .        .       . \n\
.. .. ..................O000O........................ ...... ..."

#endif
