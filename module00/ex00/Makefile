
NAME = megaphone

SRC = megaphone.cpp

CC = clang++
FLAG = -Wall -Wextra -Werror
RM = rm -f

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
