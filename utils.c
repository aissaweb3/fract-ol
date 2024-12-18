
#include <math.h>
#include "complex.h"

t_complex	mul(t_complex a, t_complex b)
{
	t_complex	result;
	
	result.Re = ((a.Re * b.Re) - (b.Im * a.Im));
	result.Im = ((a.Re * b.Im) + (b.Re * a.Im));
	
	return (result);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	result;
	
	result.Re = a.Re + b.Re;
	result.Im = a.Im + b.Im;
	
	return (result);
}


char    is_in_mandelbrot(t_complex z, t_complex c)
{
    t_complex z_n = z;
    int max_iterations = 1000;
    int i;
    for (i = 0; i < max_iterations; i++)
    {
        z_n = add(mul(z_n, z_n), c);
        if (sqrt(z_n.Re * z_n.Re + z_n.Im * z_n.Im) > 2)
            return 0; // Diverged
    }
    return 1; // Inside Mandelbrot set
}
