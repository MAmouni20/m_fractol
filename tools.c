/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:05:34 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/18 14:27:49 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_light_pixel(t_mlx *start, int x, int y, int color)
{
	int i;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	i = x * 4 + WIDTH * 4 * y;
	start->img_str[i] = (color * 15 - 7) % 255;
	start->img_str[i + 1] = (color * 44) % 255;
	start->img_str[i + 2] = (color * 77 + 16) % 255;
}

void	ft_init_mlx(t_mlx *mlx)
{
	int bpp;
	int en;
	int sl;

	mlx->init = NULL;
	mlx->init = mlx_init();
	if (mlx->init)
	{
		mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "mo");
		mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	}
	mlx->img_str = (unsigned char *)mlx_get_data_addr(mlx->img, &bpp, &sl, &en);
	mlx->x_f = 2.1;
	mlx->color = 5;
	mlx->x_i = -2.1;
	mlx->y_f = 2.1;
	mlx->y_i = -2.1;
	mlx->itr_max = 50;
}

void	maps(char **av, t_mlx *mlx)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		mlx->fract = 'M';
		mandlbrot(mlx);
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		mlx->fract = 'J';
		mlx->c_r = -0.8;
		mlx->c_i = 0.156;
		julia(mlx);
	}
	else if (!ft_strcmp(av[1], "burninship"))
	{
		mlx->fract = 'B';
		burninship(mlx);
	}
	else
	{
		ft_putstr("Maps available: mandelbrot, julia, burninship\n");
		exit(0);
	}
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_mlx *mlx, double x, double y, char mode)
{
	double	interpolation;

	if (mode == 1)
	{
		mlx->itr_max += 1;
		interpolation = 0.9 / 1;
	}
	else
	{
		mlx->itr_max -= 1;
		interpolation = 1 / 0.9;
	}
	mlx->x_i = interpolate(x, mlx->x_i, interpolation);
	mlx->x_f = interpolate(x, mlx->x_f, interpolation);
	mlx->y_i = interpolate(y, mlx->y_i, interpolation);
	mlx->y_f = interpolate(y, mlx->y_f, interpolation);
}
