/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:41:21 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/12 17:17:22 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **a, t_stack **b)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	if (*a == 0)
		return (-1);
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (*b == 0)
	{
		free(*a);
		return (-1);
	}
	(*a)->size = 0;
	(*b)->size = 0;
	(*a)->top = 0;
	(*b)->top = 0;
	(*a)->bottom = 0;
	(*b)->bottom = 0;
	(*a)->last_chunk = 0;
	(*a)->sorted_index = -1;
	return (0);
}
