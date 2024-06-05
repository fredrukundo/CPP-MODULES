#Colors:
GREEN			=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY			=	\e[33;2;37m
RESET			=	\e[0m
CURSIVE		=	\e[33;3m

NAME		= a.out
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

HEADER	= AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

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