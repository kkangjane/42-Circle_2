/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:47:15 by jae-kang          #+#    #+#             */
/*   Updated: 2024/01/02 12:13:20 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	image_making(t_mlx *mlx, t_data *img)
{
	int	*bpp;
	int	*line;
	int	*endian;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, "jae-kang's window");
	if (mlx->win == 0)
		return (-1);
	img->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	if (img->img == 0)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (-1);
	}
	bpp = &(img->bpp);
	line = &(img->line_length);
	endian = &(img->endian);
	img->addr = mlx_get_data_addr(img->img, bpp, line, endian);
	if (img->addr == 0)
	{
		mlx_destroy_image(mlx->mlx, img->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (-1);
	}
	return (0);
}

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	check_file_format(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (-1);
	if (file_name[len - 1] != 'f')
		return (-1);
	if (file_name[len - 2] != 'd')
		return (-1);
	if (file_name[len - 3] != 'f')
		return (-1);
	if (file_name[len - 4] != '.')
		return (-1);
	return (1);
}

int	free_split(char **s1, int r)
{
	int	i;

	if (s1)
	{
		i = 0;
		while (s1[i])
			free(s1[i++]);
		free(s1);
	}
	return (r);
}

int	free_map(t_map *map, int r)
{
	int	i;

	if (map->point)
	{
		i = 0;
		while (map->point[i])
			free(map->point[i++]);
	}
	return (r);
}
