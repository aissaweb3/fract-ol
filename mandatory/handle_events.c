/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_events.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ioulkhir <ioulkhir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 22:23:44 by ioulkhir		  #+#	#+#			 */
/*   Updated: 2024/12/27 22:26:00 by ioulkhir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"
#include "events.h"

int	scroll_handler(int button, int x, int y, void *param)
{
	t_fractal	*fractal;
	double		mouse_x_fractal;
	double		mouse_y_fractal;
	double		zoom_factor;

	fractal = (t_fractal *)param;
	mouse_x_fractal = map(x, WIDTH, -2, 1) * fractal->zoom + fractal->shift_x;
	mouse_y_fractal = map(y, HEIGHT, -1, 2) * fractal->zoom + fractal->shift_y;
	if (button == SCROLL_UP)
		zoom_factor = 1.1;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal->shift_x = mouse_x_fractal - map(x, WIDTH, -2, 1) * fractal->zoom;
	fractal->shift_y = mouse_y_fractal - map(y, HEIGHT, -1, 2) * fractal->zoom;
	fill_img(fractal);
	return (0);
}

int	julia_mouse_handler(int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->mouse_track == 0)
		return (0);
	fractal->julia_x = map(x, WIDTH, -2, 1);
	fractal->julia_y = map(y, HEIGHT, -1, 2);
	fill_img(fractal);
	return (0);
}

static int	close_window(void *param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	free(fractal->mlx_connection);
	fractal->mlx_connection = NULL;
	exit(0);
}

int	key_press_handler(int keycode, void *param)
{
	t_fractal	*fractal;
	double		shift_val;

	fractal = (t_fractal *)param;
	shift_val = 0.1;
	if (keycode == KEY_LEFT)
		fractal->shift_x += map(shift_val, WIDTH, -2, 1) * fractal->zoom;
	else if (keycode == KEY_RIGHT)
		fractal->shift_x -= map(shift_val, WIDTH, -2, 1) * fractal->zoom;
	else if (keycode == KEY_UP)
		fractal->shift_y += map(shift_val, HEIGHT, -1, 2) * fractal->zoom;
	else if (keycode == KEY_DOWN)
		fractal->shift_y -= map(shift_val, HEIGHT, -1, 2) * fractal->zoom;
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
		mlx_hook(fractal->mlx_window, 6, 0,
			julia_mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_NOTIFY, 0, close_window, fractal);
	mlx_key_hook(fractal->mlx_window, key_press_handler, fractal);
}
