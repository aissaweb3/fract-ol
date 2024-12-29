/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:39 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:44:42 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "events_bonus.h"

int	scroll_handler(int button, int x, int y, void *param)
{
	t_fractal	*fractal;
	double		old_zoom;
	double		zoom_factor;

	fractal = (t_fractal *)param;
	old_zoom = fractal->zoom;
	if (button == SCROLL_UP)
		zoom_factor = 1.1;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal->shift_x -= map(x, WIDTH, DFLT_WDTH_MIN, DFLT_WDTH_MAX) * (fractal->zoom - old_zoom);
	fractal->shift_y -= map(y, HEIGHT, DFLT_HGHT_MIN, DFLT_HGHT_MAX) * (fractal->zoom - old_zoom);
	fill_img(fractal);
	return (0);
}

int	julia_mouse_handler(int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->mouse_track == 0)
		return (0);
	fractal->julia_x = map(x, WIDTH, DFLT_WDTH_MIN, DFLT_WDTH_MAX);
	fractal->julia_y = map(y, HEIGHT, DFLT_HGHT_MIN, DFLT_HGHT_MAX);
	fill_img(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(0);
}

int	key_press_handler(int keycode, void *param)
{
	t_fractal	*fractal;
	double		shift_val;

	fractal = (t_fractal *)param;
	shift_val = 0.1;
	if (keycode == KEY_LEFT)
		fractal->shift_x += map(shift_val, WIDTH, DFLT_WDTH_MIN, DFLT_WDTH_MAX) * fractal->zoom;
	else if (keycode == KEY_RIGHT)
		fractal->shift_x -= map(shift_val, WIDTH, DFLT_WDTH_MIN, DFLT_WDTH_MAX) * fractal->zoom;
	else if (keycode == KEY_UP)
		fractal->shift_y += map(shift_val, HEIGHT, DFLT_HGHT_MIN, DFLT_HGHT_MAX) * fractal->zoom;
	else if (keycode == KEY_DOWN)
		fractal->shift_y -= map(shift_val, HEIGHT, DFLT_HGHT_MIN, DFLT_HGHT_MAX) * fractal->zoom;
	else if (keycode == MINUS_KEY)
		fractal->iterations_count -= 10;
	else if (keycode == PLUS_KEY)
		fractal->iterations_count += 10;
	else if (keycode == LEFT_SHIFT)
		fractal->mouse_track = !(fractal->mouse_track);
	else if (keycode == ESC_KEY)
		close_window(fractal);
	fill_img(fractal);
	return (0);
}

void	handle_events(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->mlx_window, scroll_handler, fractal);
	if (fractal->name[0] == 'J')
		mlx_hook(fractal->mlx_window, ON_MOUSEMOVE, 0,
			julia_mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_NOTIFY, 0, close_window, fractal);
	mlx_key_hook(fractal->mlx_window, key_press_handler, fractal);
}
