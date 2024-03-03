NAME = pipex
SRCS = mandatory/main.c mandatory/parsing.c mandatory/utils.c
OBJS = $(SRCS:.c=.o)
BNS_SRCS = bonus/main.c bonus/parsing.c bonus/utils.c bonus/control_fd.c bonus/find_cmd.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c
BNS_OBJS = $(BNS_SRCS:.c=.o)
LAST_ALL = ~/goinfre/last_all
LAST_BONUS = ~/goinfre/last_bonus
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CC = cc -Wall -Wextra -Werror

%.o : %.c
	$(CC) -c $^ -o $@

$(NAME) : all

all : $(LAST_ALL)
bonus : $(LAST_BONUS)
	
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(LAST_ALL) : $(LIBFT) $(OBJS)
	rm -rf $(LAST_BONUS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	touch $@

$(LAST_BONUS) : $(LIBFT) $(BNS_OBJS)
	rm -rf $(LAST_ALL)
	$(CC) $(BNS_OBJS) -o $(NAME) $(LIBFT)
	touch $@

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)
	rm -rf $(BNS_OBJS)
	rm -rf $(LAST_ALL) $(LAST_BONUS)

fclean : 
	make clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re :
	make fclean
	make all