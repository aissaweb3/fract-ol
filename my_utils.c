

#include "fractol.h"


void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


double	ft_atoi_dbl(char *str)
{
	double	dec_part;
	double	int_part;
	int		sign;
	double	i;

	int_part = 0;
	dec_part = 0.0;
	sign = 1;
	while (*str && *str == ' ')
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		int_part *= 10;
		int_part += *str - '0';
		str++;
	}
	if (!*str || *str != '.')
		return (int_part);
	++str;
	i = 0.1;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		dec_part += (*str - '0') * i;
		i /= 10;
		str++;
	}
	return ((int_part + dec_part) * sign);
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
