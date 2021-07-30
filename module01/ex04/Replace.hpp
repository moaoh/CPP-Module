#	ifndef REPLACE_HPP
#	define REPLACE_HPP

#	include <iostream>
#	include <fstream>

class Replace
{
private:
	std::string FILENAME;
	std::string	old_value;
	std::string new_value;

public:
	Replace();
	~Replace();
	std::string	cout_value(std::string type);
	int			value_validation();
};

#	endif