# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 00:56:07 by frukundo          #+#    #+#              #
#    Updated: 2024/03/24 01:04:56 by frukundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

NAME		= Account
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC		= Account.cpp tests.cpp

OBJ		= $(SRC:.cpp=.o)

HEADER	= Account.hpp

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
