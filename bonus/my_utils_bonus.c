/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:10:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:10:02 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char			*px_addr;
	unsigned long	img_width;
	unsigned long	pixel_index;
	unsigned long	pixel_size;

	img_width = img->line_length;
	pixel_size = img->bits_per_pixel / 8;
	pixel_index = y * img_width + x * pixel_size;
	px_addr = img->addr + pixel_index;
	*(unsigned int *)px_addr = color;
}

double	ft_atoi_dbl(char *str)
{
	double	dec_part;
	double	int_part;
	int		sign;
	double	i;

	1 && (int_part = 0, dec_part = 0.0, sign = 1, i = 0.1);
	while (*str && *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		1 && (str++, sign = -1);
	while (*str && ('0' <= *str && *str <= '9'))
	{
		int_part = 10 * int_part + *str - '0';
		str++;
	}
	if (*str == 0 || *str != '.')
		return (int_part);
	while (*(++str) && ('0' <= *str && *str <= '9'))
	{
		dec_part += (*str - '0') * i;
		i /= 10;
	}
	return ((int_part + dec_part) * sign);
}

double	map(double input, double old_max, double new_min, double new_max)
{
	return (((input - 0) / (old_max - 0)) * (new_max - new_min) + new_min);
}
