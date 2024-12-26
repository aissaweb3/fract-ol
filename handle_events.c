
#include "fractol.h"

int    scroll_handler(int button, int x, int y, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;
    //printf("scroll");
    printf("x y --> %d %d\n", x, y);
    printf("x y --> %d %d\n", x - (WIDTH  / 2), y - (HEIGHT / 2));
    if (button == 4)
        fractal->zoom *= 1.1;
    else if (button == 5)
        fractal->zoom *= 0.9;
    fractal->shift_x = x - (WIDTH  / 2);
    fractal->shift_y = y - (HEIGHT / 2);
    fill_img(fractal);
    return (0);
}

int    julia_mouse_track(int x, int y, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;

	fractal->julia_x = map(x, 0, WIDTH  , -2, +1);
	fractal->julia_y = map(y, 0, HEIGHT , -1, +2);
    
    fill_img(fractal);
    return (0);
}

void    handle_events(t_fractal *fractal)
{


    mlx_mouse_hook(fractal->mlx_window, scroll_handler, fractal);


	if (fractal->name[0] == 'j')
            mlx_hook(fractal->mlx_window, 6, (1L << 6), julia_mouse_track, fractal);




}
