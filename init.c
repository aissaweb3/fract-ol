/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ioulkhir <ioulkhir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 22:18:20 by ioulkhir		  #+#	#+#			 */
/*   Updated: 2024/12/27 22:22:49 by ioulkhir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

static char	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
		1 && (s1++, s2++);
	return (*s1 - *s2);
}

char	invalid(char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		return (1);
	if (!ft_strcmp(name, "Julia"))
		return (2);
	if (!ft_strcmp(name, "Burningship"))
		return (3);
	if (!ft_strcmp(name, "Tricon"))
		return (4);
	return (0);
}

static void	continue_init(t_fractal *fractal,
		char fractal_index, int argc, char **argv)
{
	fractal->diversion_radius = 2;
	fractal->iterations_count = 240;
	if (fractal_index == 1 || fractal_index == 2)
		fractal->math_func = mandelbrot_julia_func;
	else if (fractal_index == 3)
		fractal->math_func = burningship_func;
	else if (fractal_index == 4)
		fractal->math_func = tricon_func;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->mouse_track = 1;
	if (fractal_index == 2 && argc >= 4)
	{
		fractal->julia_x = ft_atoi_dbl(argv[2]);
		fractal->julia_y = ft_atoi_dbl(argv[3]);
	}
	fractal->zoom = 1;
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
}

char	fractal_init(t_fractal *fractal, int argc, char **argv)
{
	char	*name;
	char	fractal_index;

	if (argc == 1)
		return (1);
	name = argv[1];
	fractal_index = invalid(name);
	if (fractal_index == 0)
		return (1);
	fractal->name = name;
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		(write(1, "mlx connection error", 21), exit(0));
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH,
			HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
		(write(1, "error creating window", 55), free(fractal->mlx_connection), exit(0));
	fractal->img.img = mlx_new_image(fractal->mlx_connection,
			WIDTH,
			HEIGHT);
	continue_init(fractal, fractal_index, argc, argv);
	return (0);
}
