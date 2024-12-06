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

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX_PATH = ./mlx
PRINTF_PATH = ./printf

INCLUDE = -I$(MLX_PATH) -Iincludes -I$(PRINTF_PATH)

LIBMLX = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
LIBPRINTF = $(PRINTF_PATH)/libftprintf.a

FILES = so_long src/check_map src/error src/utils src/check_extension \
				src/read_map src/get_next_line src/check_rectangular \
				src/check_characters src/check_player src/check_walls \
				src/check_ecp src/window src/ft_free src/render src/moves \
				src/player_moves src/get_player_position src/validate_path \
				src/validate_path_utils

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

ifeq ($(DEBUG), 1)
	OPTS = -g;
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBPRINTF)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDE) $(LIBMLX) $(LIBPRINTF) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@$(CC)  -c -o $@ $< $(INCLUDE)

$(LIBPRINTF):
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(LIBPRINTF)... $(RESET)\n"
	@make -s -C $(PRINTF_PATH)

clean:
	@$(RM) $(OBJ)
	@make -s -C $(PRINTF_PATH) clean
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(PRINTF_PATH) fclean
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
