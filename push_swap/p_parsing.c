/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:44:22 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 15:46:57 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	dup_check(int n, t_stack *stack);
static	int	push(char *num, t_stack **stack);

int	parsing(char *argv[], t_stack **a)
{
	int		i;
	int		j;
	char	**mid;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			return (-1);
		mid = ft_split(argv[i++], ' ');
		if (mid == 0 || (mid != 0 && mid[0] == 0))
			return (free_split(&mid));
		j = 0;
		while (mid[j])
			if (push(mid[j++], a) == -1)
				return (-1);
		free_split(&mid);
	}
	if ((*a)->size == 0)
		return (-1);
	i = 0;
	while (i < (*a)->size)
		find_node(*a, i++)->chunk = 0;
	(*a)->top->next = 0;
	return (0);
}

static	int	push(char *num, t_stack **stack)
{
	long long	n;
	t_node		*new;

	n = ft_atoi(num);
	if (n == 2147483648)
		return (-1);
	if (dup_check(n, *stack) == -1)
		return (-1);
	new = (t_node *) malloc(sizeof(t_node));
	if (new == 0)
		return (-1);
	new->value = (int) n;
	new->next = 0;
	if ((*stack)->size == 0)
	{
		(*stack)->size = 1;
		(*stack)->bottom = new;
		(*stack)->top = new;
		return (0);
	}
	(*stack)->size += 1;
	new->next = (*stack)->bottom;
	(*stack)->bottom = new;
	return (0);
}

static	int	dup_check(int n, t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (0);
	node = stack->bottom;
	while (node)
	{
		if (node->value == (int) n)
			return (-1);
		node = node->next;
	}
	return (0);
}
