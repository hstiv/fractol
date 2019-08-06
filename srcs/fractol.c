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

int				threw(char *s)
{
	if (s == NULL)
		exit(0);
	write(1, s, ft_strlen(s));
	exit(0);
}

int				check_args(int c, char **s, t_mlx *frc)
{
	int			i;

	i = 0;
	if (c != 2)
		return (0);
	if (ft_strequ("julia", s[1]))
		frc->frac[0] = 1;
	else if (ft_strequ("mandelbrot", s[1]))
		frc->frac[1] = 1;
	else if (ft_strequ("mandelbar", s[1]))
		frc->frac[2] = 1;
	else if (ft_strequ("b_ship", s[1]))
		frc->frac[3] = 1;
	else if (ft_strequ("p_buffalo", s[1]))
		frc->frac[4] = 1;
	while (i < 5)
		if (frc->frac[i++] == 1)
			return(1);
	return(0);
}

int				draw_fractal(t_mlx *mlx)
{
	t_mand		m;

	init_mand(mlx->iter, &m, mlx);
	while (++m.y < HEIGHT)
	{
		m.x = -1;
		while (++m.x < WIDTH)
		{
			m.c.im = m.max.im - m.y * m.factor.im;
			m.z = init_complex(m.c.re, m.c.im);
			m.iteration = 0;
			while (pow(m.z.re, 2.0) + pow(m.z.im, 2.0) <= 4
			&& m.iteration < m.max_iteration)
			{
				define_fractal(mlx, &m);
				m.iteration++;
			}
			set_color_m(mlx, &m, m.i);
			m.i++;
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
	return (1);
}

int				main(int c, char **s)
{
	t_mlx		mlx;

	if (!check_args(c, s, &mlx))
		threw(USAGE);
	mlx.iter = 50;
	mlx.ptr = mlx_init();
	mlx.wind = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, WIND);
	mlx.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.picture = (int *) mlx_get_data_addr(mlx.img,
	&mlx.bit_per_pixel, &mlx.size_line, &mlx.endian);
	mlx_hook(mlx.wind, 17, (1L << 17), expose_hook, &mlx);
	mlx_hook(mlx.wind, 4, 0, mouse_move, &mlx);
	mlx_hook(mlx.wind, 2, 0, key_press, &mlx);
	mlx_hook(mlx.wind, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.wind, 4, 0, mouse_move, &mlx);
	mlx_loop_hook(mlx.ptr, draw_fractal, &mlx);
	mlx_loop(mlx.ptr);
	exit(0);
}
