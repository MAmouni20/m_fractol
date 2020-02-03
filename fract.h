/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:00:47 by mmostafa          #+#    #+#             */
/*   Updated: 2019/11/15 18:47:33 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

# define HEIGHT  800
# define WIDTH   800
# define X_I -2
# define X_F 2
# define Y_I -2
# define Y_F 2
# define ZOOM 150
# define HEIGHT_M abs((Y_I - Y_F) * ZOOM)
# define WIDTH_M abs((X_I - X_F) * ZOOM)

typedef	struct		s_mlx
{
	double			x;
	double			y;
	double			color;
	double			itr_max;
	double			zxp;
	double			zyp;
	double			tmp;
	double			c_r;
	double			c_i;
	double			zx;
	double			zy;
	double			x_f;
	double			x_i;
	double			y_i;
	double			y_f;
	int				itr;
	void			*img;
	void			*win;
	void			*init;
	int				mode;
	char			fract;
	unsigned char	*img_str;
}					t_mlx;

void				ft_light_pixel(t_mlx *start, int x, int y, int color);
void				ft_init_mlx(t_mlx *mlx);
void				zoom(t_mlx *mlx, double x, double y, char mode);
void				maps(char **av, t_mlx *mlx);
void				mandlbrot(t_mlx *m);
void				julia(t_mlx *j);
void				burninship(t_mlx *b);

#endif
