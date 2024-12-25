

#include "complex.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char			*dst;
	unsigned int	img_width;
	unsigned int	pixel_index;
	unsigned int	pixel_size;

	img_width = data->line_length;
	pixel_index = y * img_width + x;
	pixel_size = (data->bits_per_pixel / 8);

	dst = data->addr + (pixel_index * pixel_size);
	*(unsigned int*)dst = color;
}
