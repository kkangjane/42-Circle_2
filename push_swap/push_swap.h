/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:54:23 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 15:54:55 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CM 3

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				chunk;
	struct s_node	*next;
}t_node;

typedef struct t_stack
{
	int		sorted_index;
	int		last_chunk;
	int		size;
	t_node	*bottom;
	t_node	*top;
}t_stack;

/* ===============.=============== */

void		p(t_stack **to, t_stack **from);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rra(t_stack **stack, int print);
void		rrb(t_stack **stack, int print);
void		rrr(t_stack **a, t_stack **b);
void		ra(t_stack **stack, int print);
void		rb(t_stack **stack, int print);
void		rr(t_stack **a, t_stack **b);
void		sa(t_stack **stack, int print);
void		sb(t_stack **stack, int print);
void		swap_big(t_stack **stack);
void		ss(t_stack **a, t_stack **b);
void		swap_a(t_stack **a, t_stack **b);
long long	ft_atoi(char *string);
char		**ft_split(char const *s, char c);
void		all_sort(t_stack **a, t_stack **b);
void		all_sort2(t_stack **a, t_stack **b);
void		all_sort3(t_stack **a, t_stack **b);
void		sort_arr(int *arr[], int num);
int			find_pivot(t_stack	*stack, int start);
t_node		*find_node(t_stack *stack, int index);
void		free_all(t_stack **a, t_stack **b);
int			free_split(char ***nums);
int			init_stack(t_stack **a, t_stack **b);
int			is_sorted(t_stack *stack);
void		push_top(t_stack **stack, t_node *new);
void		push_bottom(t_stack **stack, t_node *new);
t_node		*pop_top(t_stack **stack);
t_node		*pop_bottom(t_stack **stack);
int			parsing(char *argv[], t_stack **a);
void		sort_main(t_stack **a, t_stack **b);
void		sort_small(t_stack **a, t_stack **b, int size);
void		sort2(t_stack **a, t_stack **b);
void		sort3(t_stack **a, t_stack **b);

#endif
