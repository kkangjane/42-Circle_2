/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:56:44 by jae-kang          #+#    #+#             */
/*   Updated: 2023/12/29 14:49:54 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_exit(t_mlx *mlx);
static int	key_control(int key, t_mlx *mlx);

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2 || check_file_format(argv[1]) < 0)
		error_exit("Wrong Argument");
	if (alloc_map(argv[1], &mlx.map) < 0)
		error_exit("map allocating error");
	if (parsing(argv[1], &mlx.map) < 0)
		error_exit("Parsing error");
	if (image_making(&mlx, &(mlx.img)) < 0)
		error_exit("image making error");
	iso(mlx.map);
	fit_image(mlx.map);
	draw(&(mlx.img), mlx.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 17, 0, close_exit, &mlx);
	mlx_key_hook(mlx.win, key_control, &mlx);
	mlx_loop(mlx.mlx);
	close_exit(&mlx);
	return (0);
}

static int	close_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	exit(0);
}

static int	key_control(int key, t_mlx *mlx)
{
	if (key == 53)
		close_exit(mlx);
	return (0);
}
