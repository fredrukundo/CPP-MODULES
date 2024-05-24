# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 05:30:50 by frukundo          #+#    #+#              #
#    Updated: 2024/05/17 05:31:58 by frukundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors:
GREEN		=	\e[92;5;118m
YELLOW	=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE	=	\e[33;3m


NAME		= brain

CC			= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@printf "$(_SUCCESS) $(GREEN)		- Executable ready.\n$(RESET)"

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW)		- Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)		- Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all fclean clean re