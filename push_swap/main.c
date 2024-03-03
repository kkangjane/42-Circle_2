/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:36:45 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/16 14:50:17 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_sorted_index(t_stack *a);
static	int	sorted_index(int *arr, t_stack *a);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (init_stack(&a, &b) == -1)
		return (0);
	if (parsing(argv, &a) == -1)
	{
		write(2, "Error\n", 6);
		free_all(&a, &b);
		return (0);
	}
	a->sorted_index = find_sorted_index(a);
	sort_main(&a, &b);
	free_all(&a, &b);
	return (1);
}

static	int	find_sorted_index(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *) malloc(sizeof(int) * (a->size));
	if (arr == 0)
		return (-1);
	i = 0;
	node = a->bottom;
	while (node)
	{
		arr[i++] = node->value;
		node = node->next;
	}
	sort_arr(&arr, a->size);
	i = sorted_index(arr, a);
	free(arr);
	return (i);
}

static	int	sorted_index(int *arr, t_stack *a)
{
	t_node	*node;
	int		i;

	i = 0;
	node = a->bottom;
	while (node)
	{
		if (node->value != arr[i])
			break ;
		i++;
		a->sorted_index += 1;
		node = node->next;
	}
	return (i - 1);
}
