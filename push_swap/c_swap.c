/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:10:00 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 14:25:06 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack, int print)
{
	t_node	*temp;

	if ((*stack)->size < 2)
		return ;
	if (print)
		write(1, "sa\n", 3);
	temp = find_node(*stack, (*stack)->size - 2);
	if ((*stack)->size == 2)
	{
		temp = (*stack)->top;
		temp->next = (*stack)->bottom;
		(*stack)->bottom = temp;
		(*stack)->top = temp->next;
		(*stack)->top->next = 0;
	}
	if ((*stack)->size > 2)
		swap_big(stack);
}

void	sb(t_stack **stack, int print)
{
	t_node	*temp;

	if ((*stack)->size < 2)
		return ;
	if (print)
		write(1, "sb\n", 3);
	temp = find_node(*stack, (*stack)->size - 2);
	if ((*stack)->size == 2)
	{
		temp = (*stack)->top;
		temp->next = (*stack)->bottom;
		(*stack)->bottom = temp;
		(*stack)->top = temp->next;
		(*stack)->top->next = 0;
	}
	if ((*stack)->size > 2)
		swap_big(stack);
}

void	swap_big(t_stack **stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	c = find_node(*stack, (*stack)->size - 3);
	b = c->next;
	a = b->next;
	c->next = a;
	b->next = 0;
	a->next = b;
	(*stack)->top = b;
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	sa(a, 0);
	sb(b, 0);
}

void	swap_a(t_stack **a, t_stack **b)
{
	if ((*b)->size <= 1)
	{
		sa(a, 1);
		return ;
	}
	else if ((*b)->top->chunk == find_node(*b, (*b)->size - 2)->chunk)
	{
		if ((*b)->top->value < find_node(*b, (*b)->size - 2)->value)
		{
			ss(a, b);
			return ;
		}	
	}
	sa(a, 1);
}
