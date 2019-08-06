/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:51:51 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/06 17:51:52 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose_hook(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->ptr, mlx->wind);
	exit(0);
}

int             key_press(int keycode, t_mlx *mlx)
{
	t_mlx		*param;

	if (keycode == 53)
		exit (0);
	param = mlx;
	keycode = 0;
    return (0);
}
