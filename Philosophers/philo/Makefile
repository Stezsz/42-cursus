# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:25:24 by strodrig          #+#    #+#              #
#    Updated: 2025/01/07 11:25:24 by strodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Iincludes -Wall -Wextra -Werror
RM = rm -f

FILES = philo utils/ft_puterror utils/ft_calloc utils/ft_atoi \
			ft_create_philo ft_init_info utils/ft_get_time \
			ft_print_msg ft_join_free ft_philosophers actions \


SRC = $(FILES:=.c)
OBJ = $(FILES:=.o)
HEADER = includes/philo.h

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

ifeq ($(DEBUG), 1)
	OPTS = -g
endif

.PHONE: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all
