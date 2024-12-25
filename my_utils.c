

#include "fractol.h"


void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
// {
// 	char			*dst;
// 	unsigned int	img_width;
// 	unsigned int	pixel_index;
// 	unsigned int	pixel_size;

// 	img_width = img->line_length;
// 	pixel_index = y * img_width + x;
// 	pixel_size = (img->bits_per_pixel / 8);

// 	dst = img->addr + (pixel_index * pixel_size);
// 	*(unsigned int*)dst = color;
// }
