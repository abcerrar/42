#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *f, int color)
{
	char	*dst;
	// WIDTH * 4 = line_length
	// Last 4 = bytes_per_pixel / 8
	dst = f->addr + (f->y * WIDTH * 4 + f->x * 4);
	*(unsigned int*)dst = color;
}


void draw_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2, int color) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float increment_x = (float)dx / (float)steps;
    float increment_y = (float)dy / (float)steps;

    float x = p1.x;
    float y = p1.y;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(mlx_ptr, win_ptr, round(x), round(y), color);
        x += increment_x;
        y += increment_y;
    }
}


void	create_img(t_fractal *fractal)
{
	int bytes_per_pixel;
	int line_length;
	int endian;

	fractal -> img = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
	//Blindarlo
	fractal -> addr = mlx_get_data_addr(fractal -> img, &bytes_per_pixel, &line_length, &endian);
}


int		close_window(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	return (0);
}
