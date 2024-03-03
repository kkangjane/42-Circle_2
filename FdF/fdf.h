/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:11 by jae-kang          #+#    #+#             */
/*   Updated: 2024/01/02 12:10:26 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./gnl/gnl.h"
# include "./mlx/mlx.h"

# define WIN_X  1400
# define WIN_Y  1000
# define _USE_MATH_DEFINES

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}t_point;

typedef struct s_map
{
	t_point	**point;
	int		width;
	int		height;
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	double	zoom;
}t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	img;
}t_mlx;

// utils.c
int		image_making(t_mlx *mlx, t_data *img);
void	error_exit(char *str);
int		check_file_format(char *file_name);
int		free_split(char **s1, int r);
int		free_map(t_map *map, int r);

// parsing.c
int		parsing(char *file, t_map **map);
int		alloc_map(char *file, t_map **map);

// iso.c
void	iso(t_map *map);

// zoom.c
void	fit_image(t_map *map);

// draw.c
void	mlx_draw(t_data *img, t_point p);
void	draw(t_data *img, t_map *map);

#endif