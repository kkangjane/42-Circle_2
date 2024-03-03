/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arr_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:44:19 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 15:44:30 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr[], int num)
{
	int	i;
	int	j;
	int	temp;

	if (num <= 1)
		return ;
	i = 0;
	j = 1;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if ((*arr)[i] < (*arr)[j])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}
