/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:52:03 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/20 13:49:23 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_zoom(t_mlx *fr, double mre, double mim, double zoom)
{
	double		intrpltn;

	intrpltn = 1.0 / zoom;
	(*fr).min.re = mre + ((*fr).min.re - mre) * intrpltn;
	(*fr).min.im = mim + ((*fr).min.im - mim) * intrpltn;
	(*fr).max.re = mre + ((*fr).max.re - mre) * intrpltn;
	(*fr).max.im = mim + ((*fr).max.im - mim) * intrpltn;
}

int				julia_motion(int x, int y, t_mlx *mlx)
{
	mlx->k = init_complex(
		4 * ((double)x / WIDTH - 0.5),
		4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	return (1);
}

int				mouse_move(int x, int y, t_mlx *mlx)
{
	(mlx->frac == 1) ? julia_motion(x, y, mlx) : 0;
	draw_fractal(mlx);
	return (0);
}

int				zoom(int key, int x, int y, t_mlx *mlx)
{
	double	mre;
	double	mim;

	mre = (double)x /
	(WIDTH / (mlx->max.re - mlx->min.re)) + mlx->min.re;
	mim = (double)y /
	(HEIGHT / (mlx->max.im - mlx->min.im)) + mlx->min.im;
	if (key == 5)
		ft_zoom(mlx, mre, mim, 1.05);
	if (key == 4)
		ft_zoom(mlx, mre, mim, 1 / 1.05);
	return (1);
}

int				mouse_press(int keycode, int x, int y, t_mlx *mlx)
{
	zoom(keycode, x, y, mlx);
	draw_fractal(mlx);
	return (1);
}
