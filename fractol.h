

#ifndef X
# define X

#include <math.h>
#include <mlx.h>
#include <stdio.h>

# define WIDTH  2000
# define HEIGHT 2000

typedef struct s_complex
{
	double	Re;
	double	Im;
}	t_complex;

typedef void (*fractal_function)(t_complex *, void *);

typedef struct	s_img_data {
	void	*img;
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
	
	// properties
	double				diversion_radius;
	int					iterations_count;
	fractal_function	math_func;
	
	double				shift_x;
	double				shift_y;
	double				zoom;
	
	t_img_data			img;
	
	
}	t_fractal;



void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void			fractal_init(t_fractal *fractal, char *name);
void			fill_img(t_fractal *fractal);
unsigned int	calc_pixel_color(int x, int y, t_fractal *fractal);

// complex math
t_complex		mul(t_complex a, t_complex b);
t_complex		add(t_complex a, t_complex b);
double			complex_module(t_complex z);

double			map(double input, double old_min, double old_max, double new_min, double new_max);

void			mandelbrot_julia_func(t_complex *z, void *params);
void			julia_func(t_complex *z, void *params);

#endif
