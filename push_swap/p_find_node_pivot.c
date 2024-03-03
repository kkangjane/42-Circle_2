/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_find_node_pivot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:10:17 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 16:24:26 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_stack	*stack, int start)
{
	int		*arr;
	t_node	*node;
	int		i;
	int		pivot;

	arr = (int *) malloc(sizeof(int) * (stack->size - start));
	node = find_node(stack, start);
	i = 0;
	while (i < stack->size - start)
	{
		arr[i++] = node->value;
		node = node->next;
	}
	sort_arr(&arr, stack->size - start);
	pivot = arr[(stack->size - start) / 2];
	free(arr);
	return (pivot);
}

t_node	*find_node(t_stack *stack, int index)
{
	t_node	*node;
	int		i;

	if (stack->size < index + 1)
		return (0);
	i = 0;
	node = stack->bottom;
	while (i != index)
	{
		node = node->next;
		i++;
	}
	return (node);
}
