#include <mlx.h>

#include "complex.h"
#include <math.h>
#include <stdio.h>

#define WIN_WIDTH 1000
#define WIN_HEIGHT 800


int color_condition(int x, int y)
{
    t_complex point;
    t_complex c;

    point.Re = (x / 600.0) - 2.0;  // Adjust scaling for better visualization
    point.Im = (y / 600.0) - 1.5;
    c.Re = point.Re;
    c.Im = point.Im;

    if (is_in_mandelbrot(point, c))
        return 0x000000; // Color Red for points in the set
    return 0x2AA474; // Color Black for points outside the set
}

int main()
{
    void *mlx;
    void *win;
    void *img;
    int *data;
    int bpp;
    int size_line;
    int endian;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Mandelbrot Set");

    img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    data = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);

    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
        {
            data[y * WIN_WIDTH + x] = color_condition(x, y);
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}