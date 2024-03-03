/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:01:14 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/12 15:01:33 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **a, t_stack **b)
{
	t_node	*node;
	t_node	*temp;

	if ((*a)->size != 0)
	{
		node = (*a)->bottom;
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
	}
	free(*a);
	if ((*b)->size != 0)
	{
		node = (*b)->bottom;
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
	}
	free(*b);
}

int	free_split(char ***nums)
{
	int	i;

	i = 0;
	if (*nums == 0)
		return (-1);
	while ((*nums)[i])
		free((*nums)[i++]);
	free(*nums);
	*nums = 0;
	return (-1);
}
