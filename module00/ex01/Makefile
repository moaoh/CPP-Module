
NAME = PhoneBook

SRC = \
	main.cpp \

INCLUDE_DIR = ./

CC = clang++
FLAG = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE_DIR)
RM = rm -f

OBJ = $(SRC:.cpp=.o)

# ===============================================

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)

*.o : *.cpp
	$(CC) $(FLAG) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all