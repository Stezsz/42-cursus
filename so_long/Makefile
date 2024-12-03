# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 13:27:13 by strodrig          #+#    #+#              #
#    Updated: 2024/12/02 13:27:13 by strodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX_PATH = ./mlx

INCLUDE = -I$(MLX_PATH)

LIBMLX = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

FILES = so_long src/checker/check_map

SRC = $(FILES:=.c)
OBJ = $(FILES:=.o)
HEADER = includes/so_long.h

# Cores
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]

ifeq (($(DEBUG)), 1)
	OPTS = -g;
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDE) $(LIBMLX)  -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@$(CC)  -c -o $@ $< $(INCLUDE)

clean:
	@$(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
