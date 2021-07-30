#include "Replace.hpp"

int	error_msg( std::string msg )
{
	std::cout << msg << "\n";
	return (1);
}

void	ft_replace(std::string& line, std::string s1, std::string s2)
{
	std::string::size_type	start = 0;
	std::string::size_type	num;

	while ( (num = line.find(s1, start)) != std::string::npos)
	{
		line.erase(num, s1.length());
		line.insert(num, s2);
		start = num + s2.length();
	}
}

int		file_setup( Replace& replace, std::fstream& open_file, std::fstream& write_file )
{
	if ( replace.value_validation() )
		return (1);
	open_file.open(replace.cout_value("FILENAME"), std::fstream::in);
	if ( !open_file.is_open() )
		return (error_msg("Error: Operation file corrupted"));
	write_file.open(replace.cout_value("FILENAME") + ".replace", \
					std::fstream::trunc | std::fstream::out);
	return (0);
}

int	main(void)
{
	Replace			replace;
	std::fstream	open_file;
	std::fstream	write_file;
	std::string		line;

	if ( file_setup(replace, open_file, write_file) )
		return (1);
	while ( !open_file.eof() )
	{
		getline(open_file, line);
		ft_replace(line, replace.cout_value("old_value"), replace.cout_value("new_value"));
		write_file << line << "\n";
	}

	std::cout << "Create \e[1m" + replace.cout_value("FILENAME") + ".replace ! 🎉\e[0m" << "\n";
	open_file.close();
	write_file.close();
	return (0);
}