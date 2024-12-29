/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:25 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 12:28:53 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH  800
# define HEIGHT 800

# define DWM -1
# define DWMX 1

# define DHM -1
# define DHMX 1

typedef struct s_complex
{
	double	real;
	double	im;
}	t_complex;

typedef void	(*t_fractal_function)(t_complex *, void *);

typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_fractal
{
	char				*name;
	void				*mlx_connection;
	void				*mlx_window;
	double				diversion_radius;
	int					iterations_count;
	t_fractal_function	math_func;
	double				shift_x;
	double				shift_y;
	double				zoom;
	double				julia_x;
	double				julia_y;
	char				mouse_track;
	t_img_data			img;
}	t_fractal;

// mlx
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
char			fractal_init(t_fractal *fractal, int argc, char **argv);
double			ft_atoi_dbl(char *str);
void			fill_img(t_fractal *fractal);
unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal);

// complex math
t_complex		mul(t_complex a, t_complex b);
t_complex		add(t_complex a, t_complex b);
t_complex		sub(t_complex a, t_complex b);
t_complex		conjugate(t_complex z);
double			complex_module(t_complex z);
double			map(double input, double old_max,
					double new_min, double new_max);

// fractal functions
void			mandelbrot_julia_func(t_complex *z, void *params);
void			burningship_func(t_complex *z, void *params);
void			tricon_func(t_complex *z, void *params);

// EVENTS
void			handle_events(t_fractal *fractal);

#endif