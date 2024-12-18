

#ifndef X
# define X

# define ITERATIONS_NUM 20
# define ESCAPE_VALUE 2

#include <math.h>

typedef struct s_complex
{
	double	Re;
	double	Im;
}	t_complex;

char		is_in_mandelbrot(t_complex z, t_complex c);
t_complex	mul(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);

#endif
