
NAME = megaphone

SRC = megaphone.cpp

CC = clang++
FLAG = -Wall -Wextra -Werror
RM = rm -f

OBJ = $(SRC:.cpp=.o)

# ===================================

# Color
CL_RED = \e[31m
CL_L_YELLOW = \e[93m
CL_L_BLUE = \e[94m
CL_L_MAGENTA = \e[95m

# ===================================

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ)
	@printf "$(CL_L_MAGENTA)🥳 Create megaphone 🥳\n"

%.o : %.cpp
	@$(CC) $(FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@printf "$(CL_RED)💀 Erase $(CL_L_YELLOW)*.o\n"

fclean : clean
	@$(RM) $(NAME)
	@printf "$(CL_RED)💀 Erase $(CL_L_YELLOW)megaphone\n"

re : fclean all
