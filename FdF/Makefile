NAME = fdf
SRCS = main.c parsing.c utils.c\
	draw.c iso.c zoom.c\
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
MLX = ./mlx/libmlx.a
MLX_DIR = ./mlx
LIBRARY = -L $(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit
CC = cc -Wall -Werror -Wextra

%.o : %.cc
	$(CC) -c $^ -o $@

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBRARY) -o $(NAME)

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean :
	make clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re :
	make fclean
	make all