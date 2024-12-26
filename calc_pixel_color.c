#include "fractol.h"

unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	result;
	t_complex	c;

	i = -1;
	if (fractal->name[0] == 'M')
	{
		result.Re = 0.0;
		result.Im = 0.0;
		c.Re = map(x + fractal->shift_x, 0, WIDTH , -2, +1) * fractal->zoom;
		c.Im = map(y + fractal->shift_y, 0, HEIGHT, -1, +2) * fractal->zoom;
	}else{
		c.Re = fractal->julia_x;
		c.Im = fractal->julia_y;
		result.Re = map(x + fractal->shift_x, 0, WIDTH , -2, +1) * fractal->zoom;
		result.Im = map(y + fractal->shift_y, 0, HEIGHT, -1, +2) * fractal->zoom;
	}

	while (++i < fractal->iterations_count)
	{
		(fractal->math_func)(&result, &c);
		if (complex_module(result) > fractal->diversion_radius)
			return (map(i, 0, fractal->iterations_count, 0, 0xFFFFFF)); // diversion
	}
	return (0); // black
}