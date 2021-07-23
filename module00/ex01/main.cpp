#include "phone_book.hpp"

int                 main(void)
{
    std::string     input;
    // contact_info;

    while (true)
    {
        std::getline(std::cin, input);
        if (input == "exit")
            break ;
        std::cout << input << "\n";
    }
    
    std::cout << "good bye :D" << "\n";
    return (0);
}