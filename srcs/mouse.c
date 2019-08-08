/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:52:03 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:52:06 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int				mouse_press(int keycode, int x, int y, t_mlx *mlx)
{
	t_mlx		*param;

	keycode = 0;
	x = 0;
	y = 0;
	param = mlx;
	return (1);
}
