

#ifndef X
# define X

#include <math.h>
#include <mlx.h>

# define WIDTH  800
# define HEIGHT 800

typedef struct s_complex
{
	double	Re;
	double	Im;
}	t_complex;

typedef t_complex (*fractal_function)(t_complex, t_complex);

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
	fractal_function	math_func;
	
	double				shift_x;
	double				shift_y;
	double				zoom;
	
	t_img_data			img;
	
	
}	t_fractal;



t_complex	mul(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void		fractal_init(t_fractal *fractal);

#endif
