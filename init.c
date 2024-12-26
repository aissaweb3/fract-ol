
#include "fractol.h"

void	fractal_init(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->mlx_connection = mlx_init();
	// NULLcheck
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	// NULLcheck
	fractal->img.img = mlx_new_image(fractal->mlx_connection,
										WIDTH,
										HEIGHT);

	fractal->diversion_radius = 2;
	fractal->iterations_count = 200;
	// av[1] -----> name
	fractal->math_func = mandelbrot_julia_func;

	fractal->shift_x = 0;
	fractal->shift_y = 0;

	fractal->julia_x = 0.0;
	fractal->julia_y = 0.0;
	fractal->zoom = 1;
	
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
								&fractal->img.bits_per_pixel,
								&fractal->img.line_length,
								&fractal->img.endian);


	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img, 0, 0);
	//EVEnts
}
