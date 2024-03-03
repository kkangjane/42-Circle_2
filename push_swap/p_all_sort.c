/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_all_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:55:11 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 15:18:29 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	all_sort3_1(t_stack **a, t_stack **b, int n1, int n2);

void	all_sort(t_stack **a, t_stack **b)
{
	(*a)->sorted_index = (*a)->size - 1;
	if ((*a)->size == 2)
		all_sort2(a, b);
	else if ((*a)->size == 3)
		all_sort3(a, b);
	else
		return ;
}

void	all_sort2(t_stack **a, t_stack **b)
{
	if ((*a)->bottom->value < (*a)->top->value)
		swap_a(a, b);
}

void	all_sort3(t_stack **a, t_stack **b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->top->value;
	n2 = (*a)->bottom->next->value;
	n3 = (*a)->bottom->value;
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n1 < n3 && n3 < n2)
	{
		rra(a, 1);
		swap_a(a, b);
	}
	else if (n3 < n1 && n1 < n2)
		rra(a, 1);
	else
		all_sort3_1(a, b, n1, n2);
}

static	void	all_sort3_1(t_stack **a, t_stack **b, int n1, int n2)
{
	int	n3;

	n3 = (*a)->bottom->value;
	if (n2 < n1 && n1 < n3)
		swap_a(a, b);
	if (n2 < n3 && n3 < n1)
		ra(a, 1);
	if (n3 < n2 && n2 < n1)
	{
		swap_a(a, b);
		rra(a, 1);
	}
}
