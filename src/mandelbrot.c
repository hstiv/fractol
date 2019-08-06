#include "fractol.h"

void			init_mand(int iteration, t_mand *mand)
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
	mand->x = 0;
	mand->y = 0;
	mand->max = max;
	mand->min = min;
}

void			mandelbrot(t_mlx *mlx)
{
	t_mand		m;

	init_mand(50, &m);
	while (m.y < HEIGHT)
	{
		m.c.im = m.max.im - m.y * m.factor.im;
		m.z = init_complex(m.c.re, m.c.im);
		m.iteration = 0;
		while (pow(m.z.re, 2.0) + pow(m.z.im, 2.0) <= 4
		&& m.iteration < m.max_iteration)
		{
			m.z = init_complex(
				pow(m.z.re, 2.0) - pow(m.z.im, 2.0) + m.c.re,
				2.0 * m.z.re * m.z.im + m.c.im);
				m.iteration++;
		}
		
		m.x++;
	}
	m.y++;
}