#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "f_string.h"

typedef struct	s_complex
{
	long double	re;
	long double	im;
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
	int			x;
	int			y;
}				t_mand;


typedef struct	s_mlx
{
	void		*ptr;
	void		*wind;
	void		*img;
	int			ju;
	int			man;
}				t_mlx;


/*
**				fractol.c					*
*/

int				threw(char *s);
int				check_args(int c, char **s, t_mlx *mlx);

/*
**				utils1.c					*
*/

t_complex		init_complex(double re, double im);

/*
**				mandelbrot.c				*
*/

void			init_mand(int iteration, t_mand *mand);
void			mandelbrot(t_mlx *mlx);


#endif
