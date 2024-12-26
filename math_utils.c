
#include "fractol.h"

t_complex	mul(t_complex a, t_complex b)
{
	t_complex	result;
	
	result.Re = ((a.Re * b.Re) - (b.Im * a.Im));
	result.Im = ((a.Re * b.Im) + (b.Re * a.Im));
	return (result);
}

t_complex		conjugate(t_complex z)
{
	t_complex	z_bar;

	z_bar.Re = z.Re;
	z_bar.Im = -z.Im;
	return (z_bar);
}

t_complex		div(t_complex a, t_complex b)
{
	t_complex	result;
	double		denominator;
	
	result = mul(a, conjugate(b));
	
	denominator = mul(b, conjugate(b)).Re;
	
	result.Re /= denominator;
	result.Im /= denominator;
	return (result);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	result;
	
	result.Re = a.Re + b.Re;
	result.Im = a.Im + b.Im;
	return (result);
}

t_complex	sub(t_complex a, t_complex b)
{
	t_complex	result;
	
	result.Re = a.Re - b.Re;
	result.Im = a.Im - b.Im;
	return (result);
}


double	complex_module(t_complex z)
{
	return (sqrt((z.Re * z.Re) + (z.Im * z.Im)));
}

double	map(double input, double old_min, double old_max, double new_min, double new_max)
{
	return (((input - old_min) / (old_max - old_min)) * (new_max - new_min) + new_min);
}

