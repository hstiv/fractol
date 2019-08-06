/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:52:10 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:52:11 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		init_complex(double re, double im)
{
    t_complex	complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

void			init_mand(int iteration, t_mand *mand, t_mlx *mlx)
{
	t_complex	min;
	t_complex	max;

	min = init_complex(-2.0, -2.0);
	max.re = 2.0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	mand->factor = init_complex(
    (max.re - min.re) / (WIDTH - 1),
    (max.im - min.im) / (HEIGHT - 1));
	mand->max_iteration = iteration;
	mand->iteration = 0;
	mand->y = -1;
	mand->max = max;
	mand->min = min;
	mand->i = 0;
	clear_img(mlx->picture, WIDTH * HEIGHT);
}

void			set_color_m(t_mlx *mlx, t_mand *m, int i)
{
	double		t;
	int			red;
	int			green;
	int			blue;
	int			c;

	c = m->iteration;
	t = (double)m->iteration / (double)m->max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	mlx->picture[i] = (c != m->max_iteration) ? (c << red) + (c << green) + (c << blue) : 0;
}

void            clear_img(int *img, int size)
{
    int         i;

    i = 0;
    while (i < size)
    {
        img[0] = 0;
        i++;
    }
}
