NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
SRCS =	$(SRC_DIR)setup_pipes.c \
	$(SRC_DIR)setup_files.c \
	$(SRC_DIR)utils.c \
	$(SRC_DIR)split.c \
	$(SRC_DIR)deal_with_pipes.c \
	$(SRC_DIR)execute_cmd.c \
	$(SRC_DIR)libft_utils.c \
	$(SRC_DIR)libft_utils_2.c \
	$(SRC_DIR)error.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)main.c
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
re: fclean all
