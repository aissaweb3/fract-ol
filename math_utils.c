
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


