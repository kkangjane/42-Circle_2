/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:46:59 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 10:34:00 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_stack **to, t_stack **from)
{
	t_node	*node;

	node = pop_top(from);
	if (node == 0)
		return ;
	push_top(to, node);
}

void	pa(t_stack **a, t_stack **b)
{
	if ((*b)->size <= 0)
		return ;
	write(1, "pa\n", 3);
	p(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	if ((*a)->size <= 0)
		return ;
	write(1, "pb\n", 3);
	p(b, a);
}
