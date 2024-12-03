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
PRINTF_PATH = ./ft_printf

INCLUDE = -I$(MLX_PATH) -I$(PRINTF_PATH)

LIBMLX = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
LIBPRINTF = $(PRINTF_PATH)/libftprintf.a

FILES = so_long src/checker/check_map src/checker/check_filename \
				src/checker/ft_strlen src/checker/ft_strcmp src/checker/map_error \
				src/checker/get_map src/checker/get_next_line src/checker/map_len \
				src/checker/check_elements src/checker/check_rectangular \
				src/checker/check_walls src/free_map



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

$(NAME): $(LIBPRINTF) $(OBJ)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDE) $(LIBMLX) $(LIBPRINTF) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(LIBPRINTF):
	@make -C $(PRINTF_PATH) >/dev/null 2>&1

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@$(CC)  -c -o $@ $< $(INCLUDE)

clean:
	@$(RM) $(OBJ)
	@make clean -C $(PRINTF_PATH) >/dev/null 2>&1
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(PRINTF_PATH) >/dev/null 2>&1
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
