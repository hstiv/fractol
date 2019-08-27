/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:44:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/23 12:44:03 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_struct(t_mlx *mlx)
{
	mlx->k = init_complex(-0.4, 0.6);
	mlx->iter = ITER;
	mlx->min = init_complex(-4.0, -2.0);
	mlx->max = init_complex(4.0, 2.0);
	mlx->ptr = mlx_init();
	mlx->img = NULL;
	mlx->help = 0;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->wind = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, WIND);
	mlx->picture = (int *)mlx_get_data_addr(mlx->img,
	&mlx->bit_per_pixel, &mlx->size_line, &mlx->endian);
	mlx->f[1] = &julia;
	mlx->f[2] = &mandelbrot;
	mlx->f[3] = &mandelbar;
	mlx->f[4] = &b_ship;
	mlx->f[5] = &p_buffalo;
	mlx->f[6] = &pb_ship;
	mlx->f[7] = &p_mandelbrot;
	mlx->f[8] = &c_mandelbrot;
}

int				threw(char *s, int i)
{
	if (s == NULL)
		exit(0);
	(i == 1) ? write(1, "\033[0;32m", 7) : 0;
	write(1, s, ft_strlen(s));
	exit(0);
}

int				check_args(int c, char **s, t_mlx *frc)
{
	if (c != 2)
		return (0);
	frc->frac = 0;
	(ft_strequ(JU, s[1])) ? frc->frac = 1 : 0;
	(ft_strequ(MAN, s[1])) ? frc->frac = 2 : 0;
	(ft_strequ(M_BAR, s[1])) ? frc->frac = 3 : 0;
	(ft_strequ(B_SHIP, s[1])) ? frc->frac = 4 : 0;
	(ft_strequ(P_BUF, s[1])) ? frc->frac = 5 : 0;
	(ft_strequ(PB_SHIP, s[1])) ? frc->frac = 6 : 0;
	(ft_strequ(P_MAN, s[1])) ? frc->frac = 7 : 0;
	(ft_strequ(C_MAN, s[1])) ? frc->frac = 8 : 0;
	if (frc->frac != 0)
		return (1);
	return (0);
}

void			loop(t_mlx *mlx)
{
	mlx_hook(mlx->wind, 17, (1L << 17), expose_hook, mlx);
	mlx_hook(mlx->wind, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->wind, 3, 0, key_release, mlx);
	mlx_hook(mlx->wind, 2, 0, key_press, mlx);
	mlx_hook(mlx->wind, 4, 0, mouse_press, mlx);
	mlx_loop_hook(mlx->ptr, draw_fractal, mlx);
	mlx_loop(mlx->ptr);
}

int				main(int c, char **s)
{
	t_mlx		mlx;

	if (!check_args(c, s, &mlx))
		threw(USAGE, 1);
	init_struct(mlx);
	loop(&mlx);
	exit(0);
}
