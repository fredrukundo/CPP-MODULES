#Colors:
GREEN			=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY			=	\e[33;2;37m
RESET			=	\e[0m
CURSIVE		=	\e[33;3m

NAME		= ex00
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC		= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

HEADER	= Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"
	
fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"
	
re: fclean all

.PHONY: all fclean clean re