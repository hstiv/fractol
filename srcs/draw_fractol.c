/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:55:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/20 14:23:01 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				define_fractal1(t_mand *m)
{
	if (m->frac == 5)
		m->z = init_complex(
			fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
			-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
	if (m->frac == 6)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
	if (m->frac == 7)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * fabs(m->z.re) * m->z.im + m->c.im);
	if (m->frac == 8)
		m->z = init_complex(
			fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
			-2.0 * m->z.re * m->z.im + m->c.im);
}

void				define_fractal(t_mand *m)
{
	if (m->frac == 1)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->k.re,
			2.0 * m->z.re * m->z.im + m->k.im);
	else if (m->frac == 2)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			2.0 * m->z.re * m->z.im + m->c.im);
	else if (m->frac == 3)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * m->z.re * m->z.im + m->c.im);
	else if (m->frac == 4)
		m->z = init_complex(
			pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
			-2.0 * fabs(m->z.re * m->z.im) + m->c.im);
	else
		define_fractal1(m);
}

void				*x_cycle(void *mlx)
{
	t_mand			*m;

	m = (t_mand *)mlx;
	m->i = m->y * HEIGHT / THRD;
	while (m->i < (m->y + 1) * HEIGHT / THRD)
	{
		m->x = -1;
		m->c.im = m->max.im - m->i * m->factor.im;
		while (++m->x < WIDTH)
		{
			m->c.re = m->min.re + m->x * m->factor.re;
			m->z = init_complex(m->c.re, m->c.im);
			m->iteration = 0;
			while (pow(m->z.re, 2.0) + pow(m->z.im, 2.0) <= 4
			&& m->iteration < m->max_iteration)
			{
				define_fractal(m);
				m->iteration++;
			}
			set_color_m(m);
		}
		m->i++;
	}
	pthread_exit(0);
}

void				cp_struct(t_mand *bunch, t_mlx *mlx, int y)
{
	bunch[y].frac = mlx->frac;
	bunch[y].picture = mlx->picture;
	bunch[y].k = mlx->k;
	bunch[y].iter = mlx->iter;
	bunch[y].min = init_complex(mlx->min.re, mlx->min.im);
	bunch[y].max = init_complex(mlx->max.re, mlx->max.im);
	bunch[y].factor = init_complex(
	(bunch[y].max.re - bunch[y].min.re) / (WIDTH - 1),
	(bunch[y].max.im - bunch[y].min.im) / (HEIGHT - 1));
}

int					draw_fractal(t_mlx *mlx)
{
	t_mand			m[THRD];
	pthread_t		id[THRD];
	int				i;

	i = 0;
	if (!mlx->help)
	{
		while (i < THRD)
		{
			init_mand(mlx->iter, &m[i]);
			cp_struct(m, mlx, i);
			m[i].y = i;
			pthread_create(&id[i], NULL, x_cycle, (void*)&m[i]);
			i++;
		}
		i = -1;
		while (++i < THRD)
			pthread_join(id[i], NULL);
	}
	mlx_clear_window(mlx->ptr, mlx->wind);
	mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
	put_man(mlx);
	return (1);
}
