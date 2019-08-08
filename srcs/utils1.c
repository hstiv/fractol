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

t_complex		nit_complex(double re, double im)
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
	mlx->picture = (int *)mlx_get_data_addr(mlx->img,
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
	mand->y = 0;
	mand->i = 0;
}

void			put_man(t_mlx *mlx)
{
	(mlx->help == 0) ? mlx_string_put(mlx->ptr,
	mlx->wind, WIDTH - 100, HEIGHT - 30, RED, HELP) : 0;
	if (mlx->help == 1)
	{
		mlx_string_put(mlx->ptr, mlx->wind, W4, 10, GREEN, H1);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 30, GREEN, H2);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 50, GREEN, H3);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 70, GREEN, H4);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 90, GREEN, H5);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 110, GREEN, H6);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 130, GREEN, H7);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 150, GREEN, H8);
		mlx_string_put(mlx->ptr, mlx->wind, W4, 190, GREEN, IT);
	}
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
}
