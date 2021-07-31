#	ifndef KAREN_HPP
#	define KAREN_HPP

#	include <iostream>
#	include <string>

class Karen
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Karen(/* args */);
	~Karen();
	void	karenFilter( std::string level );
};

#	endif