
#include "fractol.h"

static char	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
		1 && (s1++, s2++);
	return (*s1 - *s2);
}

char	invalid(char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		return (1);
	if (!ft_strcmp(name, "julia"))
		return (2);
	if (!ft_strcmp(name, "burningship"))
		return (3);
	if (!ft_strcmp(name, "tricon"))
		return (4);
	if (!ft_strcmp(name, "newton"))
		return (5);
	return (0);
}

char	fractal_init(t_fractal *fractal, int argc, char **argv)
{
	char	*name;
	char	fractal_index;

	name = argv[1];
	fractal_index = invalid(name);
	if (argc == 1 || fractal_index == 0)
		return (1);
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
	fractal->iterations_count = 240;
	// av[1] -----> name
	if (fractal_index == 1 || fractal_index == 2)
		fractal->math_func = mandelbrot_julia_func;
	else if (fractal_index == 3)
		fractal->math_func = burningship_func;
	else if (fractal_index == 4)
		fractal->math_func = tricon_func;
	else if (fractal_index == 5)
		fractal->math_func = newton_algo_func;

	fractal->shift_x = 0;
	fractal->shift_y = 0;


	fractal->julia_x = 0.0;
	fractal->julia_y = 0.0;
	fractal->mouse_track = 1;
	if (fractal_index == 2)
	{
		fractal->julia_x = ft_atoi_dbl(argv[2]);
		fractal->julia_y = ft_atoi_dbl(argv[3]);
	}
	fractal->zoom = 1;
	
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
								&fractal->img.bits_per_pixel,
								&fractal->img.line_length,
								&fractal->img.endian);


	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img, 0, 0);
	return (0);
}
