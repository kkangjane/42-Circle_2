/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:14:29 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/17 19:22:08 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort(t_stack **a, t_stack **b);
static	void	move_atob(t_stack **a, t_stack **b, int pivot);
static	void	move_btoa(t_stack **a, t_stack **b, int pivot, int cs);
static	void	just_move_btoa(t_stack **a, t_stack **b);

void	sort_main(t_stack **a, t_stack **b)
{
	while (1)
	{
		if (is_sorted(*a) && (*b)->size == 0)
			break ;
		sort(a, b);
	}
}

static	void	sort(t_stack **a, t_stack **b)
{
	int	cs;

	if ((*a)->sorted_index == (*a)->size - 1)
	{
		cs = (*b)->size - 1;
		while (cs >= 0 && (*b)->top->chunk == find_node(*b, cs)->chunk)
			cs--;
		cs++;
		if ((*b)->size - cs <= CM)
			just_move_btoa(a, b);
		else
			move_btoa(a, b, find_pivot(*b, cs), cs);
	}
	while ((*a)->size - (*a)->sorted_index - 1 > CM)
		move_atob(a, b, find_pivot(*a, (*a)->sorted_index + 1));
	sort_small(a, b, (*a)->size - (*a)->sorted_index - 1);
}

static	void	move_btoa(t_stack **a, t_stack **b, int pivot, int cs)
{
	int	current_chunk_i;
	int	p;

	current_chunk_i = (*b)->top->chunk;
	(*a)->last_chunk += 1;
	p = 0;
	while ((*b)->top->chunk == current_chunk_i)
	{
		(*b)->top->chunk = (*a)->last_chunk;
		if ((*b)->top->value > pivot)
		{
			pa(a, b);
			p++;
		}
		else
			rb(b, 1);
		if ((cs % 2 == 0 && p == cs / 2 - 1) || (cs % 2 == 1 && p == cs / 2))
			break ;
	}
	if ((*b)->bottom->chunk == (*b)->top->chunk)
		return ;
	while ((*b)->bottom->chunk == (*a)->last_chunk)
		rrb(b, 1);
}

static	void	just_move_btoa(t_stack **a, t_stack **b)
{
	int	i;
	int	chunk_i;

	if ((*b)->size == 0)
		return ;
	i = (*b)->size - 1;
	chunk_i = (*b)->top->chunk;
	while ((*b)->top && (*b)->top->chunk == chunk_i)
		pa(a, b);
}

static	void	move_atob(t_stack **a, t_stack **b, int pivot)
{
	int	r;
	int	current_chunk_i;

	r = 0;
	(*a)->last_chunk += 1;
	current_chunk_i = (*a)->top->chunk;
	while ((*a)->top->chunk == current_chunk_i)
	{
		(*a)->top->chunk = (*a)->last_chunk;
		if ((*a)->top->value < pivot)
			pb(a, b);
		else
		{
			ra(a, 1);
			r++;
		}
	}
	while (r > 0 && (*a)->size != r)
	{
		rra(a, 1);
		r--;
	}
}
