/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:52:10 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:52:11 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		init_complex(double re, double im)
{
    t_complex	complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

void			init_mand(int iteration, t_mand *mand, t_mlx *mlx)
{
	(mlx->img) ? mlx_destroy_image(mlx->ptr, mlx->img) : 0;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->picture = (int *) mlx_get_data_addr(mlx->img,
	&mlx->bit_per_pixel, &mlx->size_line, &mlx->endian);
	mand->min = init_complex(-2.0, -2.0);
	mand->max.re = 2.0;
	mand->max.im = mand->min.im +
	(mand->max.re - mand->min.re) * HEIGHT / WIDTH;
	mand->factor = init_complex(
    (mand->max.re - mand->min.re) / (WIDTH - 1),
    (mand->max.im - mand->min.im) / (HEIGHT - 1));
	mand->max_iteration = iteration;
	mand->iteration = 0;
	mand->y = -1;
	mand->i = 0;
}

void			set_color_m(t_mlx *mlx, t_mand *m, int i)
{
	double		t;
	int			red;
	int			green;
	int			blue;
	int			c;

	c = m->iteration;
	t = (double)m->iteration / (double)m->max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	mlx->picture[i] = (c != m->max_iteration)
	? (c << red) + (c << green) + (c << blue) : 0;
	// mlx->picture[i] = (int)(255 * t);
}
