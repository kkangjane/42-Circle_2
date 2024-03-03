/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_is_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:10:37 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 15:50:09 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return (1);
	node = stack->bottom;
	while (node->next)
	{
		if (node->value < node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
