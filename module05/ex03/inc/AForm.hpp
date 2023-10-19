#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	const std::string	target;
	bool				isSign;
	const int			signGrade;
	const int			executeGrade;

public:
	AForm(const std::string _name,
				const std::string target,
				const int _signGrade,
				const int _executeGrade);
	AForm(const AForm& src);
	AForm	&operator = (const AForm& rhs);
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	class UnsignedForm : public std::exception {
	public:
		const char *what() const throw();
	};

	std::string		getName() const;
	std::string		getTarget() const;
	bool			getIsSign() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;

	void			beSigned( const Bureaucrat& bure );
	virtual void 	execute(Bureaucrat const & executor) const = 0;

	void			checkIsSign() const;
	void			checkExecutor(Bureaucrat const & executor) const;
};

std::ostream &operator << (std::ostream& os, const AForm& other);

#endif
