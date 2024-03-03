/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:09:49 by jae-kang          #+#    #+#             */
/*   Updated: 2023/11/15 15:49:52 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *string)
{
	int			i;
	int			sign;
	long long	num;
	int			len;

	i = 0;
	num = 0;
	sign = 1;
	if (string[i] == '+' || string[i] == '-')
		if (string[i++] == '-')
			sign *= -1;
	len = 0;
	if (string[i] > '9' || string[i] < '0')
		return (2147483648);
	while (string[i] == '0')
		i++;
	while (string[i] <= '9' && string[i] >= '0')
	{
		num = num * 10 + sign * (string[i++] - '0');
		len++;
	}
	if (string[i] != 0 || num > 2147483647 || num < -2147483648 || len > 10)
		return (2147483648);
	return (num);
}
