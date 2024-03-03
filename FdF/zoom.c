/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:09:52 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/29 13:28:46 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_max_min(t_map *map);
static void	calculate_zoom(t_map *map);
static void	zoom(t_map *map);
static void	parallel_move(t_map *map, int a, int b);

void	fit_image(t_map *map)
{
	double	dx;
	double	dy;

	find_max_min(map);
	calculate_zoom(map);
	zoom(map);
	find_max_min(map);
	dx = (WIN_X - (map->max_x - map->min_x)) / 2 - map->min_x;
	dy = (WIN_Y - (map->max_y - map->min_y)) / 2 - map->min_y;
	parallel_move(map, dx, dy);
}

static void	find_max_min(t_map *map)
{
	int	i;
	int	j;

	map->min_x = map->point[0][0].x;
	map->max_x = map->point[0][0].x;
	map->min_y = map->point[0][0].y;
	map->max_y = map->point[0][0].y;
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->min_x > map->point[i][j].x)
				map->min_x = map->point[i][j].x;
			if (map->min_y > map->point[i][j].y)
				map->min_y = map->point[i][j].y;
			if (map->max_x < map->point[i][j].x)
				map->max_x = map->point[i][j].x;
			if (map->max_y < map->point[i][j].y)
				map->max_y = map->point[i][j].y;
			j++;
		}
		i++;
	}
}

static void	calculate_zoom(t_map *map)
{
	double	a;
	double	b;

	a = map->max_x - map->min_x;
	b = map->max_y - map->min_y;
	map->zoom = fmin(WIN_X / a, WIN_Y / b);
	if (map->zoom > 10)
		map->zoom -= 5;
	else
		map->zoom = ((map->zoom) / 10) * 9;
}

static void	zoom(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			map->point[i][j].x *= map->zoom;
			map->point[i][j].y *= map->zoom;
			j++;
		}
		i++;
	}
}

static void	parallel_move(t_map *map, int a, int b)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			map->point[i][j].x += a;
			map->point[i][j].y += b;
			j++;
		}
		i++;
	}
}
