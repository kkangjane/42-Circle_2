SRC = c_push.c \
	c_rev_rot.c \
	c_rot.c \
	c_swap.c \
	ft_atoi.c \
	ft_split.c \
	main.c \
	p_all_sort.c \
	p_arr_sort.c \
	p_find_node_pivot.c \
	p_free.c \
	p_init_stack.c \
	p_is_sorted.c \
	p_move_node.c \
	p_parsing.c \
	p_sort.c \
	p_sort_small.c

NAME = push_swap

all : $(NAME)

$(NAME) :$(SRC)
	cc -o $@ $(SRC) -Wall -Wextra -Werror

clean :

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all
