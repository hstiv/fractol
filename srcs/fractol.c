/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:51:39 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:51:41 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		return(1);
	return(0);
}

void			fractal(t_mlx *mlx)
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
	mlx.k = init_complex(-0.4, 0.6);
	mlx.iter = 50;
	mlx.ptr = mlx_init();
	mlx.img = NULL;
	mlx.help = 0;
	mlx.wind = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, WIND);
	fractal(&mlx);
	exit(0);
}
