/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:55:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 19:56:08 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			define_fractal1(t_mlx *mlx, t_mand *m)
{
	if (mlx->frac == 5)
		m->z = init_complex(
			fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
			-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
	if (mlx->frac == 6)
		m->z = init_complex(
        pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
        -2.0 * m->z.re * fabs(m->z.im) + m->c.im);
	if (mlx->frac == 7)
		m->z = init_complex(
        pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
        -2.0 * fabs(m->z.re) * m->z.im + m->c.im);
	if (mlx->frac == 8)
		m->z = init_complex(
        fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
        -2.0 * m->z.re * m->z.im + m->c.im);
}

void			define_fractal(t_mlx *mlx, t_mand *m)
{
	if (mlx->frac == 1)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + mlx->k.re,
			2.0 * m->z.re * m->z.im + mlx->k.im);
	else if (mlx->frac == 2)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			2.0 * m->z.re * m->z.im + m->c.im);
	else if (mlx->frac == 3)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * m->z.re * m->z.im + m->c.im);
	else if (mlx->frac == 4)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * fabs(m->z.re * m->z.im) + m->c.im);
	else
		define_fractal1(mlx, m);
}

void			x_cycle(t_mlx *mlx, t_mand *m)
{
	m->x = -1;
	m->c.im = m->max.im - m->y * m->factor.im;
	while (++m->x < WIDTH)
	{
		m->c.re = m->min.re + m->x * m->factor.re;
		m->z = init_complex(m->c.re, m->c.im);
		m->iteration = 0;
		while (pow(m->z.re, 2.0) + pow(m->z.im, 2.0) <= 4
		&& m->iteration < m->max_iteration)
		{
			define_fractal(mlx, m);
			m->iteration++;
		}
		set_color_m(mlx, m, m->i);
		m->i++;
	}
}

int				draw_fractal(t_mlx *mlx)
{
	t_mand		m;

	init_mand(mlx->iter, &m, mlx);
	if (!mlx->help)
	{
		while (++m.y < HEIGHT)
			x_cycle(mlx, &m);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
	put_man(mlx);
	return (1);
}
