#include "fractol.h"

void			julia(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->k.re,
		2.0 * m->z.re * m->z.im + m->k.im);
}

void			mandelbrot(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		2.0 * m->z.re * m->z.im + m->c.im);
}

void			mandelbar(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		-2.0 * m->z.re * m->z.im + m->c.im);
}

void			b_ship(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		-2.0 * fabs(m->z.re * m->z.im) + m->c.im);
}