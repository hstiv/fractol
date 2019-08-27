/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:44:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/23 12:52:41 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				mlx->f[mlx->frac](m);
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
	while (i < THRD)
	{
		init_mand(mlx->iter, &m[i]);
		cp_struct(m, mlx, i);
		m[i].y = i;
		pthread_create(&id[i], NULL, x_cycle, (void*)&m[i]);
		i++;
	}
	while (i >= 0)
		pthread_join(id[i--], NULL);
	mlx_clear_window(mlx->ptr, mlx->wind);
	mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
	put_man(mlx);
	return (1);
}
