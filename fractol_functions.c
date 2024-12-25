


#include "fractol.h"






void	mandelbrot_julia_func(t_complex *z, void *params)
{
	t_complex *c = (t_complex *)params;
	*z = (add(mul(*z, *z), *c));
}

