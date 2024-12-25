#include "fractol.h"

unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	result;
	t_complex	c;

	i = -1;
	c.Re = -0.7;
	c.Im = 0.0;
	result.Re = map(x, 0, WIDTH , -2, +1) * fractal->zoom + fractal->shift_x;
	result.Im = map(y, 0, HEIGHT, -1, +2) * fractal->zoom + fractal->shift_y;

	while (++i < fractal->iterations_count)
	{
		result = (fractal->math_func)(&result, &c);
		if (complex_module(result) > fractal->diversion_radius)
			return (0xFFFF00); // diversion
	}
	return (0); // black
}
