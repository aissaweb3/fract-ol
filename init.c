
#include "complex.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	// NULLcheck
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	// NULLcheck
	fractal->img.img = mlx_new_image(fractal->mlx_connection, 1920, 1080);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
								&fractal->img.bits_per_pixel,
								&fractal->img.line_length,
								&fractal->img.endian);
	my_mlx_pixel_put(&fractal->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img, 0, 0);
	mlx_loop(fractal->mlx_connection);
	//EVEnts
}
