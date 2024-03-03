/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:50:19 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/27 20:47:18 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_size(char *file, t_map *map);
static int	count_arr(char **s);
static int	put_points(char *line, t_map **map, int y);

int	parsing(char *file, t_map **map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (put_points(line, map, y++) < 0)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	alloc_map(char *file, t_map **map)
{
	int	i;

	*map = (t_map *) malloc(sizeof(t_map));
	if (*map == 0)
		return (-1);
	(*map)->width = 0;
	(*map)->height = 0;
	if (get_map_size(file, *map) < 0)
		return (-1);
	i = (*map)->width * (*map)->height * sizeof(t_point);
	(*map)->point = (t_point **) malloc(i);
	if (!(*map)->point)
		return (-1);
	i = 0;
	while (i < (*map)->width)
	{
		(*map)->point[i] = (t_point *) malloc(sizeof(t_point) * (*map)->height);
		if ((*map)->point[i] == 0)
			return (free_map(*map, -1));
		i++;
	}
	return (0);
}

static int	get_map_size(char *file, t_map *map)
{
	int		fd;
	char	**temp;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_split(line, ' ');
		free(line);
		if (!temp)
		{
			close(fd);
			return (-1);
		}
		map->width = count_arr(temp);
		free_split(temp, 0);
		map->height += 1;
	}
	close(fd);
	return (0);
}

static int	count_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i] && s[i][0] != '\n')
		i++;
	return (i);
}

static int	put_points(char *line, t_map **map, int y)
{
	int		i;
	char	**p;

	p = ft_split(line, ' ');
	if (!p)
		return (-1);
	i = 0;
	while (i < (*map)->width)
	{
		((*map)->point)[i][y].x = (double) i;
		((*map)->point)[i][y].y = (double) y;
		((*map)->point)[i][y].z = (double) ft_atoi(p[i]);
		i++;
	}
	free_split(p, 0);
	return (0);
}
