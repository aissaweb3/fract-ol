


#include "fractol.h"

t_complex	mandelbrot_func(t_complex *z, void *params)
{
	return (add(mul(*z, *z), *(t_complex *)params));
}

t_complex	julia_func(t_complex *z, void *params)
{
	return (add(mul(*(t_complex *)params, *(t_complex *)params), *z));
}
