/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:35:49 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 12:41:49 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack **stack, t_node *new)
{
	new->next = 0;
	if ((*stack)->size == 0)
	{
		(*stack)->bottom = new;
		(*stack)->top = new;
		(*stack)->size = 1;
		return ;
	}
	(*stack)->top->next = new;
	(*stack)->top = new;
	(*stack)->size += 1;
}

void	push_bottom(t_stack **stack, t_node *new)
{
	if ((*stack)->size == 0)
	{
		(*stack)->bottom = new;
		(*stack)->top = new;
		(*stack)->size = 1;
		return ;
	}
	new->next = (*stack)->bottom;
	(*stack)->bottom = new;
	(*stack)->size += 1;
}

t_node	*pop_top(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->size == 0)
		return (0);
	temp = (*stack)->top;
	temp->next = 0;
	if ((*stack)->size == 1)
	{
		(*stack)->size = 0;
		(*stack)->top = 0;
		(*stack)->bottom = 0;
		return (temp);
	}
	(*stack)->top = find_node(*stack, (*stack)->size - 2);
	(*stack)->top->next = 0;
	(*stack)->size -= 1;
	return (temp);
}

t_node	*pop_bottom(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->size == 0)
		return (0);
	temp = (*stack)->bottom;
	if ((*stack)->size == 1)
	{
		(*stack)->size = 0;
		(*stack)->top = 0;
		(*stack)->bottom = 0;
		return (temp);
	}
	(*stack)->bottom = (*stack)->bottom->next;
	temp->next = 0;
	(*stack)->size -= 1;
	return (temp);
}
