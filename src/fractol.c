#include "fractol.h"

int				threw(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

int				check_args(int c, char **s, t_mlx *frc)
{
	if (c != 2)
		return (0);
	frc->ju = 0;
	frc->man = 0;
	if (ft_strequ("julia", s[1]))
	{
		frc->ju = 1;
		return (1);
	}
	else if (ft_strequ("mandelbrot", s[1]))
	{
		frc->man = 1;
		return (1);
	}
	return(0);
}

int				main(int c, char **s)
{
	t_mlx		mlx;

	if (!check_args(c, s, &mlx))
		threw(USAGE);
	mlx.ptr = mlx_init();
	mlx.wind = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, WIND);
	
	mlx_destroy_image(mlx.ptr, mlx.img);
	mlx_destroy_window(mlx.ptr, mlx.wind);
	exit(0);
}
