


#include "fractol.h"






void	mandelbrot_julia_func(t_complex *z, void *params)
{
	t_complex *c = (t_complex *)params;
	*z = (add(mul(*z, *z), *c));
}

t_complex	func_a(t_complex z)
{
	t_complex	one;

	one.Re = 1;
	one.Im = 0;
	return (sub(mul(z, mul(z, z)), one));
}

t_complex	func_a_derivative(t_complex z)
{
	t_complex	three;

	three.Re = 3;
	three.Im = 0;
	return (mul(mul(z, z), three));
}

void	newton_algo_func(t_complex *z, void *params)
{
	*z = sub(*z, div(func_a(*z), func_a_derivative(*z)));
}

void	burningship_func(t_complex *z, void *params)
{
    t_complex abs_zn;
    t_complex c;
    
	c = *(t_complex *)params;

    abs_zn.Re = fabs(z->Re);
    abs_zn.Im = fabs(z->Im);

    *z = add(mul(abs_zn, abs_zn), c);
}


void	tricon_func(t_complex *z, void *params)
{
	t_complex *c;
	
	c = (t_complex *)params;
	*z = (add(mul(conjugate(*z), conjugate(*z)), *c));
}