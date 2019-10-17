#include "fractol.h"

void			p_buffalo(t_mand *m)
{
	m->z = init_complex(
		fabs(m->z.re * m->z.re - m->z.im * m->z.im) + m->c.re,
		-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
}

void			pb_ship(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		2.0 * m->z.re * m->z.im + m->c.im);
}

void			p_mandelbrot(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		-2.0 * m->z.re * m->z.im + m->c.im);
}

void			p_mandelbar(t_mand *m)
{
	m->z = init_complex(
		m->z.re * m->z.re - m->z.im * m->z.im + m->c.re,
		-2.0 * fabs(m->z.re * m->z.im) + m->c.im);
}