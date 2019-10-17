/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:52:10 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/20 14:19:21 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_global_var()
{
	form[0] = &julia;
	form[1] = &mandelbrot;
	form[2] = &mandelbar;
	form[3] = &b_ship;
	form[4] = &p_buffalo;
	form[5] = &pb_ship;
	form[6] = &p_mandelbrot;
	form[7] = &p_mandelbar;
}

t_complex		init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void			init_mand(int iteration, t_mand *mand)
{
	mand->max_iteration = iteration;
	mand->iteration = 0;
	mand->y = 0;
	mand->i = 0;
}

void			put_man(t_mlx *mlx)
{
	if (mlx->help == 0)
		mlx_string_put(mlx->ptr,
		mlx->wind, WIDTH - 100, HEIGHT - 30, RED, HELP);
	else if (mlx->help == 1)
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

void			set_color_m(t_mand *m)
{
	double		t;
	int			red;
	int			green;
	int			blue;
	int			c;

	c = m->iteration;
	t = (double)m->iteration / (double)m->max_iteration;
	if (t == 1)
		m->picture[m->i * WIDTH + m->x] = 0;
	else
	{
		red = (int)(9 * (1 - t) * t * t * t * 255);
		green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		m->picture[m->i * WIDTH + m->x] = (c != m->max_iteration)
		? (c << red) + (c << green) + (c << blue) : 0;
	}
}
