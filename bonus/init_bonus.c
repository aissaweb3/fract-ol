/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:45 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 12:43:37 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static char	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
		1 && (s1++, s2++);
	return (*s1 - *s2);
}

static char	invalid(char *name, int argc)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		return ((argc == 2) * 1);
	if (!ft_strcmp(name, "Julia"))
		return ((argc == 4) * 2);
	if (!ft_strcmp(name, "Burningship"))
		return ((argc == 2) * 3);
	if (!ft_strcmp(name, "Tricon"))
		return ((argc == 2) * 4);
	return (0);
}

static void	continue_init(t_fractal *fractal,
		char fractal_index, int argc, char **argv)
{
	fractal->diversion_radius = 4;
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
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
}

static void	mlx_failure(t_fractal *fractal)
{
	if (fractal->mlx_connection)
	{
		if (fractal->img.img_ptr)
			mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		if (fractal->mlx_window)
			mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	}
	write(2, "Minilibx error !\n", 18);
	exit(0);
}

char	fractal_init(t_fractal *fractal, int argc, char **argv)
{
	char	fractal_index;

	if (argc == 1)
		return (1);
	fractal->name = argv[1];
	fractal_index = invalid(fractal->name, argc);
	if (fractal_index == 0)
		return (1);
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		(mlx_failure(fractal));
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH,
			HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
		(mlx_failure(fractal));
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
		(mlx_failure(fractal));
	continue_init(fractal, fractal_index, argc, argv);
	return (0);
}
