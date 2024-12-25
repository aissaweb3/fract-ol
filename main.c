
#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	//check argv
	fractal_init(&fractal, av[1]);

	fill_img(&fractal);
	
	mlx_loop(fractal.mlx_connection);
	
}