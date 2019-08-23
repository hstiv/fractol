/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:43:10 by hstiv             #+#    #+#             */
/*   Updated: 2019/08/23 12:50:15 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

# define JU			"julia"
# define MAN		"mandelbrot"
# define M_BAR		"mandelbar"
# define B_SHIP		"b_ship"
# define P_BUF		"p_buffalo"
# define PB_SHIP	"pb_ship"
# define P_MAN		"p_mandelbrot"
# define C_MAN		"c_mandelbrot"

/*
**			USAGE		*
*/
# define WIND		"fract'ol"
# define USAGE		"\n Usage :  ./fractol [fractol_name]\n\n" USAGE1
# define USAGE1		"---> " JU "\n" USAGE2
# define USAGE2		"---> " MAN "\n" USAGE3
# define USAGE3		"---> " M_BAR "\n" USAGE4
# define USAGE4		"---> " B_SHIP " (burning ship)\n" USAGE5
# define USAGE5		"---> " P_BUF " (perpendicular buffalo)\n" US6
# define US6		"---> " PB_SHIP " (perpendicular burning ship)\n" US7
# define US7		"---> " P_MAN " (perpendicular mandelbrot)\n" US8
# define US8		"---> " C_MAN " (celtic mandelbrot)\n\n"

/*
**			HELP - difines			*
*/
# define HELP		"H - help"
# define H1			"1 - julia"
# define H2			"2 - mandelbrot"
# define H3			"3 - mandelbar"
# define H4			"4 - burning ship"
# define H5			"5 - perpendicular buffalo"
# define H6			"6 - perpendicular burning ship"
# define H7			"7 - perpendicular mandelbrot"
# define H8			"8 - celtic mandelbrot"
# define IT			"< / > - iteration"

# define HEIGHT		1395
# define WIDTH		1900
# define WHITE		16777215
# define GREEN		65280
# define RED		16711680
# define YELLOW		65525
# define ORANGE		16682752
# define PINK		16715426
# define W4			WIDTH - 300
# define THRD		8

#endif
