
NAME	= so_long
CC = cc
GCC = gcc
VFLAGS = -g
CFLAGS	= -Wall -Wextra -Werror
SRC	= so_long.c events.c utils.c
OBJ	= $(SRC:.c=.o)
MLX	= -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx-linux
	$(CC) $(CFLAGS) libft/*.c $(OBJ)  $(MLX) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

vazamento: $(OBJ)
	@make -C libft
	@make -C minilibx-linux
	$(GCC) $(VFLAGS) libft/*.c $(OBJ)  $(MLX) -o $(NAME)
	valgrind --leak-check=full ./so_long

