/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:51:30 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:51:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "f_string.h"

/*
**	------------STRUCTURES-------------*
*/

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef	struct	s_mand
{
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	t_complex	min;
	t_complex	max;
	int			max_iteration;
	int			iteration;
	int			i;
	int			x;
	int			y;
}				t_mand;


typedef struct	s_mlx
{
	int			frac;
	void		*ptr;
	void		*wind;
	void		*img;
	int			*picture;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	int			iter;
	t_complex	k;
}				t_mlx;

/*
**	------------FUNCTIONS-------------	*
*/

/*
**				fractol.c					*
*/
int				threw(char *s, int i);
int				check_args(int c, char **s, t_mlx *mlx);
int				draw_fractal(t_mlx *mlx);

/*
**				keyboard.c					*
*/
int				key_press(int keycode, t_mlx *mlx);
int				expose_hook(void *param);

/*
**				mouse.c						*
*/
int             julia_motion(int x, int y, t_mlx *fractol);
int				mouse_move(int x, int y, t_mlx *mlx);
int				mouse_press(int keycode, int x, int y, t_mlx *mlx);

/*
**				utils1.c					*
*/
t_complex		init_complex(double re, double im);
void			init_mand(int iteration, t_mand *mand, t_mlx *mlx);
void			set_color_m(t_mlx *mlx, t_mand *m, int i);

/*
**				draw_fractol.c				*
*/
void			define_fractal(t_mlx *mlx, t_mand *m);
void			define_fractal1(t_mlx *mlx, t_mand *m);

#endif
