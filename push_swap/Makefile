# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 17:26:39 by strodrig          #+#    #+#              #
#    Updated: 2024/12/07 15:02:17 by strodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

STACK		= $(addprefix stack/, new_elem free_stack pop_elem poop_elem \
			  push_elem push_elem_bottom init_stack)
OPERATION	= $(addprefix operations/, pa_push_a pb_push_b ra_rotate_a \
				  rb_rotate_b rr_ra_rb rra_reverse_rotate_a \
				  rrb_reverse_rotate_b rrr_rra_rrb sa_swap_a sb_swap_b \
				  ss_sa_sb)
CHECKS		= $(addprefix checks/, get_input is_sorted is_empty is_integer is_duplicates \
			  is_greater_than_int put_error)
UTILS		= $(addprefix utils/, ft_split ft_swap ft_atoi ft_strcmp ft_putstr)
ALGO		= $(addprefix algorithm/, generic_sort basic_sort chunks_sort sort_three \
			  get_chunk_elem get_elem_index get_max get_min push_to_stack_a \
			  push_chunk_elems)
FILES		= $(addprefix srcs/, push_swap $(STACK) $(OPERATION) $(UTILS) $(CHECKS) $(ALGO))

SRC			= $(FILES:=.c)
OBJ			= $(FILES:=.o)
HEADER		= $(addprefix includes/, push_swap.h)
INCLUDES	= -I includes

# Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

# Debug
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(OPTS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(OPTS) $(INCLUDES) -c $< -o $@

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

