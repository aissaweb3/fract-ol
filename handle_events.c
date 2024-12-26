
#include "fractol.h"

int    scroll_handler(int button, int x, int y, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;
    //printf("scroll");
    if (button == 4)
        fractal->zoom *= 1.2;
    else if (button == 5)
        fractal->zoom *= 0.8;
    
	// fractal->shift_x = map(x, 0, WIDTH  , -2, +1) * fractal->zoom;
	// fractal->shift_y = map(y, 0, HEIGHT , -1, +2) * fractal->zoom;
	
    fill_img(fractal);
    return (0);
}

int    julia_mouse_handler(int x, int y, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;

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

int key_press_handler(int keycode, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;
    if (keycode == KEY_LEFT)
        fractal->shift_x += map(1, 0, WIDTH  , -2, +1) * fractal->zoom;
    else if (keycode == KEY_RIGHT)
        fractal->shift_x -= map(1, 0, WIDTH  , -2, +1) * fractal->zoom;
    else if (keycode == KEY_UP)
        fractal->shift_y += map(1, 0, HEIGHT , -1, +2) * fractal->zoom;
    else if (keycode == KEY_DOWN)
        fractal->shift_y -= map(1, 0, HEIGHT , -1, +2) * fractal->zoom;
        
    else if (keycode == MINUS_KEY)
        fractal->iterations_count -= 10;
    else if (keycode == PLUS_KEY)
        fractal->iterations_count += 10;
        
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
