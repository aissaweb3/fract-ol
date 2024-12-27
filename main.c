
#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	char error = fractal_init(&fractal, ac, av);
	if (error)
		return (1);

	fill_img(&fractal);
	
	handle_events(&fractal);

	mlx_loop(fractal.mlx_connection);
}