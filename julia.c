/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:38:36 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/15 18:33:12 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	julia(t_mlx *j)
{
	j->y = -1;
	while (++j->y < HEIGHT)
	{
		j->x = -1;
		while (++j->x < WIDTH)
		{
			j->zy = -(j->y / HEIGHT) * fabs(j->y_i - j->y_f) - j->y_i;
			j->zx = (j->x / WIDTH) * fabs(j->x_i - j->x_f) + j->x_i;
			j->itr = 0;
			while (j->itr < j->itr_max &&
					((j->zx * j->zx) + (j->zy * j->zy)) < 4)
			{
				j->tmp = j->zx;
				j->zx = j->zx * j->zx - j->zy * j->zy + j->c_r;
				j->zy = 2 * j->tmp * j->zy + j->c_i;
				j->itr++;
			}
			if (j->itr == j->itr_max)
				ft_light_pixel(j, j->x, j->y, 0);
			else
				ft_light_pixel(j, j->x, j->y, j->color + j->itr);
		}
	}
}
