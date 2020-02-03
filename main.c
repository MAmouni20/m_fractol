/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:12:55 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/18 14:30:06 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	wich_map(char map, t_mlx *mlx)
{
	if (map == 'M')
		mandlbrot(mlx);
	if (map == 'J' || map == 'S')
		julia(mlx);
	if (map == 'B')
		burninship(mlx);
}

int		key_press(int key_code, t_mlx *mlx)
{
	if (key_code == 8)
	{
		ft_bzero(mlx->img_str, WIDTH * HEIGHT * 4);
		if (mlx->color >= 1412376245.000000)
			mlx->color = 70 % (int)mlx->itr_max;
		mlx->color *= 7;
		wich_map(mlx->fract, mlx);
	}
	if (key_code == 49 && mlx->fract == 'J')
		mlx->fract = 'S';
	else if (key_code == 49 && mlx->fract == 'S')
		mlx->fract = 'J';
	if (key_code == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		mouse_motion(int x, int y, t_mlx *mlx)
{
	if (mlx->fract == 'J')
	{
		ft_bzero(mlx->img_str, WIDTH * HEIGHT * 4);
		mlx->c_r = x / (WIDTH / (mlx->x_f - mlx->x_i)) + mlx->x_i;
		mlx->c_i = y / (HEIGHT / (mlx->y_f - mlx->y_i)) + mlx->y_i;
		julia(mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	double xx;
	double yy;

	if (button == 4)
	{
		ft_bzero(mlx->img_str, WIDTH * HEIGHT * 4);
		xx = x / (WIDTH / (mlx->x_f - mlx->x_i)) + mlx->x_i;
		yy = y / (HEIGHT / (mlx->y_f - mlx->y_i)) + mlx->y_i;
		zoom(mlx, xx, yy, 0);
	}
	if (button == 5)
	{
		ft_bzero(mlx->img_str, WIDTH * HEIGHT * 4);
		xx = x / (WIDTH / (mlx->x_f - mlx->x_i)) + mlx->x_i;
		yy = y / (HEIGHT / (mlx->y_f - mlx->y_i)) + mlx->y_i;
		zoom(mlx, xx, yy, 1);
	}
	wich_map(mlx->fract, mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	ac = 0;
	if (!av[1])
	{
		ft_putstr("choose at least one map\n");
		return (0);
	}
	ft_init_mlx(&mlx);
	maps(av, &mlx);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 6, 0, mouse_motion, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_hook, &mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
