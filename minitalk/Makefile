# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 12:54:11 by strodrig          #+#    #+#              #
#    Updated: 2024/10/12 12:45:27 by strodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Name:
NAME        = minitalk
CLIENT      = client
SERVER      = server

# ft_printf Variables:
LIBFTPRINTF     = ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ft_printf

# Minitalk Variables:
SRC_C       = ft_client.c
SRC_S       = ft_server.c
OBJ_S       = ft_server.o
OBJ_C       = ft_client.o
OBJ_PRINTF  = $(LIBFTPRINTF_DIR)/ft_printf.o $(LIBFTPRINTF_DIR)/ft_atoi.o
INC         = ft_minitalk.h

# Compiling Variables:
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(OBJ_PRINTF) $(INC)
	@ $(CC) $(CFLAGS) $(OBJ_S) $(OBJ_PRINTF) $(LIBFTPRINTF) -o $(SERVER)
	@printf "server ready.\n"

$(CLIENT): $(OBJ_C) $(OBJ_PRINTF) $(INC)
	@ $(CC) $(CFLAGS) $(OBJ_C) $(OBJ_PRINTF) $(LIBFTPRINTF) -o $(CLIENT)
	@printf "client ready.\n"

%.o: %.c $(INC)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S) $(OBJ_PRINTF)
	@printf "object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "client removed.\n"
	@printf "server removed.\n"

re: fclean all

.PHONY: all clean fclean re


