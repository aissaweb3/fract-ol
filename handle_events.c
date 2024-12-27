
#include "fractol.h"

# define SCROLL_UP 4
# define SCROLL_DOWN 5

int scroll_handler(int button, int x, int y, void *param)
{
    t_fractal *fractal;
    double mouse_x_fractal;
    double mouse_y_fractal;
    double zoom_factor;

    fractal = (t_fractal *)param;
    mouse_x_fractal = map(x, 0, WIDTH, -2, +1) * fractal->zoom + fractal->shift_x;
    mouse_y_fractal = map(y, 0, HEIGHT, -1, +2) * fractal->zoom + fractal->shift_y;
    if (button == SCROLL_UP)
        zoom_factor = 1.1;
    else if (button == SCROLL_DOWN)
        zoom_factor = 0.9;
    else
        return (0);
    fractal->zoom *= zoom_factor;
    fractal->shift_x = mouse_x_fractal - map(x, 0, WIDTH, -2, +1) * fractal->zoom;
    fractal->shift_y = mouse_y_fractal - map(y, 0, HEIGHT, -1, +2) * fractal->zoom;
    fill_img(fractal);
    return (0);
}



int    julia_mouse_handler(int x, int y, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;

    if (fractal->mouse_track == 0)
        return (0);
	fractal->julia_x = map(x, 0, WIDTH  , -2, +1);
	fractal->julia_y = map(y, 0, HEIGHT , -1, +2);
    
    fill_img(fractal);
    return (0);
}

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 126
#define KEY_DOWN 125
#define ESC_KEY 53

#define PLUS_KEY 24
#define MINUS_KEY 27

#define LEFT_SHIFT 257

int key_press_handler(int keycode, void *param)
{
    t_fractal   *fractal;
    double      shift_val;

    fractal = (t_fractal *)param;
    shift_val = 0.1;
    if (keycode == KEY_LEFT)
        fractal->shift_x += map(shift_val, 0, WIDTH  , -2, +1) * fractal->zoom;
    else if (keycode == KEY_RIGHT)
        fractal->shift_x -= map(shift_val, 0, WIDTH  , -2, +1) * fractal->zoom;
    else if (keycode == KEY_UP)
        fractal->shift_y += map(shift_val, 0, HEIGHT , -1, +2) * fractal->zoom;
    else if (keycode == KEY_DOWN)
        fractal->shift_y -= map(shift_val, 0, HEIGHT , -1, +2) * fractal->zoom;
        
    else if (keycode == MINUS_KEY)
        fractal->iterations_count -= 10;
    else if (keycode == PLUS_KEY)
        fractal->iterations_count += 10;
    else if (keycode == LEFT_SHIFT)
        fractal->mouse_track = !(fractal->mouse_track);
    fill_img(fractal);
    return (0);
}

void    handle_events(t_fractal *fractal)
{


    mlx_mouse_hook(fractal->mlx_window, scroll_handler, fractal);


	if (fractal->name[0] == 'j')
            mlx_hook(fractal->mlx_window, 6, (1L << 6), julia_mouse_handler, fractal);


    mlx_key_hook(fractal->mlx_window, key_press_handler, fractal);

}
