/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:16 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/29 14:24:55 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line(t_point p1, t_point p2, t_data *img);
static void	high_inc(t_point a, t_point b, t_data *img);
static void	low_inc(t_point a, t_point b, t_data *img);

void	mlx_draw(t_data *img, t_point p)
{
	char	*dst;
	int		x;
	int		y;

	x = round(p.x);
	y = round(p.y);
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *) dst = 0xFFFFFF;
}

void	draw(t_data *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (i != map->width - 1)
				line(map->point[i][j], map->point[i + 1][j], img);
			if (j != map->height - 1)
				line(map->point[i][j], map->point[i][j + 1], img);
			j++;
		}
		i++;
	}
}

static void	line(t_point p1, t_point p2, t_data *img)
{
	double	inc;

	p1.x = round(p1.x);
	p2.x = round(p2.x);
	p1.y = round(p1.y);
	p2.y = round(p2.y);
	if (p1.x != p2.x)
		inc = (p1.y - p2.y) / (p1.x - p2.x);
	if (p1.x == p2.x || inc > 1 || inc < -1)
	{
		if (p1.y < p2.y)
			low_inc(p1, p2, img);
		else if (p1.y > p2.y)
			low_inc(p2, p1, img);
	}
	else
	{
		if (p1.x < p2.x)
			high_inc(p1, p2, img);
		else if (p1.x > p2.x)
			high_inc(p2, p1, img);
	}
}

static void	high_inc(t_point a, t_point b, t_data *img)
{
	double	inc;
	t_point	p;
	int		i;

	i = 0;
	inc = (b.y - a.y) / (b.x - a.x);
	while (a.x + i <= b.x)
	{
		p.x = a.x + i;
		p.y = a.y + inc * i;
		mlx_draw(img, p);
		i++;
	}
}

static void	low_inc(t_point a, t_point b, t_data *img)
{
	double	inc;
	t_point	p;
	int		i;

	i = 0;
	inc = (b.x - a.x) / (b.y - a.y);
	while (a.y + i < b.y)
	{
		p.x = a.x + inc * i;
		p.y = a.y + i;
		mlx_draw(img, p);
		i++;
	}
}
