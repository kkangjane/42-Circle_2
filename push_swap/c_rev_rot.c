/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rev_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:56:11 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 10:34:04 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack, int print)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if ((*stack)->size <= 1)
		return ;
	if (print)
		write(1, "rra\n", 4);
	new_bottom = (*stack)->bottom->next;
	new_top = (*stack)->bottom;
	(*stack)->top->next = new_top;
	(*stack)->top = new_top;
	new_top->next = 0;
	(*stack)->bottom = new_bottom;
}

void	rrb(t_stack **stack, int print)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if ((*stack)->size <= 1)
		return ;
	if (print)
		write(1, "rrb\n", 4);
	new_bottom = (*stack)->bottom->next;
	new_top = (*stack)->bottom;
	(*stack)->top->next = new_top;
	(*stack)->top = new_top;
	new_top->next = 0;
	(*stack)->bottom = new_bottom;
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rra(a, 0);
	rrb(b, 0);
}
