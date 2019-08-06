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
