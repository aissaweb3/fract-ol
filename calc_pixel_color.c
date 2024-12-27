/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   calc_pixel_color.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ioulkhir <ioulkhir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 22:31:14 by ioulkhir		  #+#	#+#			 */
/*   Updated: 2024/12/27 22:36:48 by ioulkhir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

static void	init_z_and_c(t_fractal *fractal, t_complex *z,
		t_complex *c, t_complex px)
{
	if (fractal->name[0] == 'J')
	{
		c->real = fractal->julia_x;
		c->im = fractal->julia_y;
		z->real = map(px.real, WIDTH, -2, 1) * fractal->zoom + fractal->shift_x;
		z->im = map(px.im, HEIGHT, -1, 2) * fractal->zoom + fractal->shift_y;
	}
	else
	{
		z->real = 0.0;
		z->im = 0.0;
		c->real = map(px.real, WIDTH, -2, 1) * fractal->zoom + fractal->shift_x;
		c->im = map(px.im, HEIGHT, -1, 2) * fractal->zoom + fractal->shift_y;
	}
}

unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	result;
	t_complex	c;
	t_complex	px;

	i = -1;
	px.real = x;
	px.im = y;
	init_z_and_c(fractal, &result, &c, px);
	while (++i < fractal->iterations_count)
	{
		(fractal->math_func)(&result, &c);
		if (complex_module(result) > fractal->diversion_radius)
			return (map(i, fractal->iterations_count, 0, 0xFFFFFF));
	}
	return (0);
}
