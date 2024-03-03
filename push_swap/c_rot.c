/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:50:33 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 10:34:08 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack, int print)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (print)
		write(1, "ra\n", 3);
	new_bottom = (*stack)->top;
	new_top = find_node(*stack, (*stack)->size - 2);
	new_top->next = 0;
	new_bottom->next = (*stack)->bottom;
	(*stack)->bottom = new_bottom;
	(*stack)->top = new_top;
}

void	rb(t_stack **stack, int print)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (print)
		write(1, "rb\n", 3);
	new_bottom = (*stack)->top;
	new_top = find_node(*stack, (*stack)->size - 2);
	new_top->next = 0;
	new_bottom->next = (*stack)->bottom;
	(*stack)->bottom = new_bottom;
	(*stack)->top = new_top;
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	ra(a, 0);
	rb(b, 0);
}
