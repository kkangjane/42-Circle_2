/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:05:35 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/27 19:56:53 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_map *map)
{
	int		x;
	int		y;
	double	z;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			z = map->point[x][y].z;
			map->point[x][y].x = sqrt(2) / 2 * (x + y);
			map->point[x][y].y = sqrt(6) / 6 * (y - x - 2 * z);
			x++;
		}
		y++;
	}
}
