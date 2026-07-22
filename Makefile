NAME = miniRT
SRCS = main.c ./parser/parser.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
CC	 = cc
RM	 = rm -f
CFLAGS = -Wall -Wextra -Werror



.PHONY: all clean fclean re

all: $(MLX) $(NAME)


$(MLX):
	make -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all