//
// Created by Admin on 27.08.2019.
//

#include "fractol.h"

void				p_buffalo(t_mand *m)
{
	m->z = init_complex(
	fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
	-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
}

void				pb_ship(t_mand *m)
{
	m->z = init_complex(
	pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
	-2.0 * m->z.re * fabs(m->z.im) + m->c.im);
}

void				p_mandelbrot(t_mand *m)
{
	m->z = init_complex(
	pow(m->z.re, 2.0) - pow(m->z.im, 2.0) + m->c.re,
	-2.0 * fabs(m->z.re) * m->z.im + m->c.im);
}

void				c_mandelbrot(t_mand *m)
{
	m->z = init_complex(
	fabs(pow(m->z.re, 2.0) - pow(m->z.im, 2.0)) + m->c.re,
	-2.0 * m->z.re * m->z.im + m->c.im);
}
