/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:51:51 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:51:52 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset_frac(t_mlx *mlx, int frac)
{
	(frac == 9) ? frac = 8 : 0;
	if (mlx->frac == frac)
	{
		draw_fractal(mlx);
		return ;
	}
	mlx->k = init_complex(-0.4, 0.6);
	mlx->iter = 50;
	mlx->frac = frac;
	draw_fractal(mlx);
}

int				expose_hook(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->ptr, mlx->wind);
	exit(0);
}

int             key_press(int key, t_mlx *mlx)
{
	(key == 53) ? exit (0) : 0;
	(key == 124) ? mlx->iter++ : 0;
	(key == 123) ? mlx->iter-- : 0;
	if (key >= 83 && key <= 91)
		reset_frac(mlx, key - 82);
    return (0);
}
