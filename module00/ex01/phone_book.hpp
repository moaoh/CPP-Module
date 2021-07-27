#	ifndef PHONE_BOOK_HPP
#	define PHONE_BOOK_HPP

// include ============================

#	include <iostream>
#	include <string>

// class ==============================

class phone_book
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void	ADD(void);
		void	blank_space(int num);
		void	cout_search(std::string& str);
		void	SEARCH(void);
		void	cout_contact(void);
};

// ====================================

#endif
