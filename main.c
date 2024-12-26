
#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac)
	fractal_init(&fractal, av[1]);

	fill_img(&fractal);
	
	handle_events(&fractal);

	mlx_loop(fractal.mlx_connection);
}