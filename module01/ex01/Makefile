
NAME = ZombieHorde

SRC = \
	main.cpp \
	Zombie.cpp \
	ZombieHorde.cpp \

INCLUDE_DIR = ./

CC = clang++
FLAG = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE_DIR)
RM = rm -f

OBJ = $(SRC:.cpp=.o)

# ==============================================

# Color
CL_RED = \e[31m
CL_L_YELLOW = \e[93m
CL_L_BLUE = \e[94m
CL_L_MAGENTA = \e[95m
CL_BOLD = \e[1m
CL_RESET = \e[0m

# ===============================================

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ)
	@printf "$(CL_L_MAGENTA)🥳 Create$(CL_RESET) $(CL_BOLD)$(NAME) 🥳\n"

%.o : %.cpp
	@$(CC) $(FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@printf "$(CL_RED)💀 Erase $(CL_L_YELLOW)*.o\n"

fclean : clean
	@$(RM) $(NAME)
	@printf "$(CL_RED)💀 Erase $(CL_L_YELLOW)$(NAME)\n"

re : fclean all