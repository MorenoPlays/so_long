
NAME	= so_long
CC = cc
CFLAGS	= -Wall -Wextra -Werror
SRC	= so_long.c
OBJ	= $(SRC:.c=.o)
MLX	= -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C minilibx-linux
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
