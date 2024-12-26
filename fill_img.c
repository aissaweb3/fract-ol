
#include "fractol.h"

void	fill_img(t_fractal *fractal)
{
	int x;
	int y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			my_mlx_pixel_put(&fractal->img, x, y, calc_pixel_color(x, y, fractal));
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img, 0, 0);
}
