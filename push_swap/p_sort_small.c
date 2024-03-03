/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sort_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:35:08 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 15:17:11 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort3_1(t_stack **a, t_stack **b, int n1, int n2);
static	void	sort3_2(t_stack **a, t_stack **b);

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if ((*a)->size <= CM)
	{
		all_sort(a, b);
		return ;
	}
	if (size <= 1)
		(*a)->sorted_index += size;
	if (size == 2)
		sort2(a, b);
	if (size == 3)
		sort3(a, b);
}

void	sort2(t_stack **a, t_stack **b)
{
	(*a)->sorted_index += 2;
	if (find_node(*a, (*a)->size - 2)->value < (*a)->top->value)
		swap_a(a, b);
}

void	sort3(t_stack **a, t_stack **b)
{
	int	n1;
	int	n2;
	int	n3;

	(*a)->sorted_index += 3;
	n1 = find_node(*a, (*a)->size - 1)->value;
	n2 = find_node(*a, (*a)->size - 2)->value;
	n3 = find_node(*a, (*a)->size - 3)->value;
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n2 < n1 && n1 < n3)
		swap_a(a, b);
	else
		sort3_1(a, b, n1, n2);
}

static	void	sort3_1(t_stack **a, t_stack **b, int n1, int n2)
{
	int	n3;

	n3 = find_node(*a, (*a)->size - 3)->value;
	if ((n1 < n3 && n3 < n2) || (n3 < n1 && n1 < n2))
	{
		pb(a, b);
		sa(a, 1);
		pa(a, b);
		if (n3 < n1 && n1 < n2)
			swap_a(a, b);
	}
	if ((n2 < n3 && n3 < n1) || (n3 < n2 && n2 < n1))
		sort3_2(a, b);
}

static	void	sort3_2(t_stack **a, t_stack **b)
{
	swap_a(a, b);
	pb(a, b);
	sa(a, 1);
	pa(a, b);
	if ((*a)->top->value > find_node(*a, (*a)->size - 2)->value)
		swap_a(a, b);
}
