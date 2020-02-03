/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burninship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:54:03 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/15 18:27:10 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	burninship(t_mlx *b)
{
	b->y = -1;
	while (++b->y < HEIGHT)
	{
		b->x = -1;
		while (++b->x < WIDTH)
		{
			b->c_r = (b->x / WIDTH) * fabs(b->x_i - b->x_f) + b->x_i;
			b->c_i = -(b->y / HEIGHT) * fabs(b->y_i - b->y_f) - b->y_i;
			b->zx = 0;
			b->zy = 0;
			b->itr = 0;
			while (b->itr < b->itr_max &&
			((b->zx * b->zx) + (b->zy * b->zy)) < 4)
			{
				b->tmp = b->zx;
				b->zx = b->zx * b->zx - b->zy * b->zy + b->c_r;
				b->zy = fabs(2 * b->tmp * b->zy) + b->c_i;
				b->itr++;
			}
			if (b->itr == b->itr_max)
				ft_light_pixel(b, b->x, b->y, 0);
			else
				ft_light_pixel(b, b->x, b->y, b->color + b->itr);
		}
	}
}
