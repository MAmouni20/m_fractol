/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlbrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:34:51 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/15 18:30:33 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandlbrot(t_mlx *m)
{
	m->y = -1;
	while (++m->y < HEIGHT)
	{
		m->x = -1;
		while (++m->x < WIDTH)
		{
			m->c_r = (m->x / WIDTH) * fabs(m->x_i - m->x_f) + m->x_i;
			m->c_i = -(m->y / HEIGHT) * fabs(m->y_i - m->y_f) - m->y_i;
			m->zx = 0;
			m->zy = 0;
			m->itr = 0;
			while (m->itr < m->itr_max &&
				((m->zx * m->zx) + (m->zy * m->zy)) < 4)
			{
				m->tmp = m->zx;
				m->zx = m->zx * m->zx - m->zy * m->zy + m->c_r;
				m->zy = 2 * m->tmp * m->zy + m->c_i;
				m->itr++;
			}
			if (m->itr == m->itr_max)
				ft_light_pixel(m, m->x, m->y, 0);
			else
				ft_light_pixel(m, m->x, m->y, m->color + m->itr);
		}
	}
}
