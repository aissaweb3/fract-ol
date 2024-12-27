#include "fractol.h"

unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	result;
	t_complex	c;

	i = -1;
	if (fractal->name[0] == 'j')
	{
		c.Re = fractal->julia_x;
		c.Im = fractal->julia_y;
		result.Re = map(x, 0, WIDTH , -2, +1) * fractal->zoom + fractal->shift_x;
		result.Im = map(y, 0, HEIGHT, -1, +2) * fractal->zoom + fractal->shift_y;
	}
	else
	{
		result.Re = 0.0;
		result.Im = 0.0;
		c.Re = map(x, 0, WIDTH , -2, +1) * fractal->zoom + fractal->shift_x;
		c.Im = map(y, 0, HEIGHT, -1, +2) * fractal->zoom + fractal->shift_y;
	}

	while (++i < fractal->iterations_count)
	{
		(fractal->math_func)(&result, &c);
		if (complex_module(result) > fractal->diversion_radius)
			return (map(i, 0, fractal->iterations_count, 0, 0xFFFFFF)); // diversion
	}
	return (0); // black
}