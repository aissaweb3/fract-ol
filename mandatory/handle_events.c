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
	double		zoom_factor;

	fractal = (t_fractal *)param;
	if (button == SCROLL_UP)
		zoom_factor = 1.1;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (x + y * 0);
	fractal->zoom *= zoom_factor;
	fill_img(fractal);
	return (0);
}

static int	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	free(fractal->mlx_connection);
	fractal->mlx_connection = NULL;
	exit(0);
}

int	key_press_handler(int keycode, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keycode == ESC_KEY)
		close_window(fractal);
	fill_img(fractal);
	return (0);
}

void	handle_events(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->mlx_window, scroll_handler, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_NOTIFY, 0, close_window, fractal);
	mlx_key_hook(fractal->mlx_window, key_press_handler, fractal);
}
