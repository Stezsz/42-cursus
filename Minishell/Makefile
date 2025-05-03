# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:57:47 by tborges-          #+#    #+#              #
#    Updated: 2025/04/26 15:25:54 by strodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # Color variables
# RESET = \033[0m
# BOLD = \033[1m
# GREEN = \033[32m
# RED = \033[31m
# YELLOW = \033[33m
# CYAN = \033[36m

# # Variables
# LIBFT = libft
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4
# INCLUDES = includes/
# IFLAGS = -I $(INCLUDES)
# SRC_DIR = src/
# OBJ_DIR = objs
# SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
# OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRCS))
# NAME = minishell

# # Rules
# all: $(NAME)
# 	@echo "$(GREEN)Build completed$(RESET)"

# $(NAME): $(OBJS)
# 	@echo "$(CYAN)Linking objects...$(RESET)"
# 	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft -lreadline
# 	@echo "$(GREEN)Executable $(NAME) created$(RESET)"

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@echo "$(YELLOW)Compiling $<...$(RESET)"
# 	mkdir -p $(dir $@)
# 	make -C $(LIBFT)
# 	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# clean:
# 	@echo "$(RED)Cleaning object files...$(RESET)"
# 	@make clean -C $(LIBFT)
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	@echo "$(RED)Cleaning executable...$(RESET)"
# 	@make fclean -C $(LIBFT)
# 	rm -f $(NAME)

# re: fclean all

# v:					$(NAME)
# 					clear && valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --track-origins=yes --suppressions=readline.supp ./minishell

# .PHONY: all clean fclean re


NAME = minishell
LIBFT = libft/libft.a
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = minishell parse/array_build/args parse/array_build/init_cmd \
		parse/array_build/redirs parse/before_lexer/before_lexer \
		parse/expander/expander parse/expander/expander2 parse/expander/here_expander \
		parse/expander/process_dollar parse/frees/free_att parse/lexer/lexer \
		parse/lexer/skips parse/lexer/tokens executer/create_path \
		executer/executer_utils executer/executer executer/handle_and_exec_cmd \
		executer/manage_redir executer/redir_auxiliars executer/built_ins/cd_and_pwd \
		executer/built_ins/echo_and_unset executer/built_ins/env_and_exit \
		executer/built_ins/export executer/built_ins/get_env \
		executer/built_ins/get_exp executer/built_ins/utils executer/built_ins/utils2 \
		executer/here_doc/here_pipe_approach executer/signals/exec_signals \
		executer/signals/here_signals executer/signals/interative \
		parse/syntax_error

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER = includes/minishell.h
INCLUDES	= -I includes -I $(LIBFT_DIR)
LDFLAGS	+= -lreadline

# leite: no meu pc dá se usar isto ############################################
# LDFLAGS += -L/opt/homebrew/opt/readline/lib -lreadline
# INCLUDES += -I/opt/homebrew/opt/readline/include -I includes -I $(LIBFT_DIR)
###############################################################################


#Colors:
GREEN		=	\033[92;5;118m
YELLOW		=	\033[93;5;226m
GRAY		=	\033[33;2;37m
RESET		=	\033[0m
CURSIVE		=	\033[33;3m

#Debug
ifeq ($(DEBUG), 1)
	OPTS = -g
endif

.PHONY: all clean fclean re norm libft

all: libft $(NAME)

libft:
	@printf "$(CURSIVE)$(GRAY) 	- Making libft... $(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)    - Libft ready.\n$(RESET)"

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(LDFLAGS) $(OPTS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) $(CFLAGS) $(INCLUDES) $(OPTS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
