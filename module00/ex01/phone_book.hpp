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
	void			ADD(void)
	{
		std::string	temp;

		std::cout << "first_name : ";
		getline(std::cin, temp);
		first_name = temp;
		std::cout << "last_name : ";
		getline(std::cin, temp);
		first_name = temp;
		std::cout << "nickname : ";
		getline(std::cin, temp);
		first_name = temp;
		std::cout << "phone_number : ";
		getline(std::cin, temp);
		first_name = temp;
		std::cout << "darkest_secret : ";
		getline(std::cin, temp);
		first_name = temp;
		std::cout << "\n";
	}
	// [  10보다  ]|[  작은      ]|[   출력     ]|[          ]
	// index, first name, last name and nickname
	void SEARCH(void)
	{

	}
	phone_book(/* args */);
	~phone_book();
};

phone_book::phone_book(/* args */)
{
}

phone_book::~phone_book()
{
}

// class ==============================

#endif