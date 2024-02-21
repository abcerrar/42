#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *f, int color)
{
	char	*dst;
	// WIDTH * 4 = line_length
	// Last 4 = bytes_per_pixel / 8
	dst = f->addr + (f->y * WIDTH * 4 + f->x * 4);
	*(unsigned int*)dst = color;
}

void	init_fractal(t_fractal *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->addr = NULL;
	f->name = "";
	f->x = 0;
	f->y = 0;
	f->shift_pressed = 0;
	f->palette = 0;
	f->color_position = 0;
	f->max_iter = 0;
	f->center_x = 0.0;
	f->center_y = 0.0;
	f->zr = 0.0;
	f->zi = 0.0;
	f->cr = 0.0;
	f->ci = 0.0;
	f->zoom = 0.0;
	f->zoom_factor = 0.0;
	f->movement_speed = 0.0;
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

void	init_fractal_values(t_fractal *f)
{
		f->zoom = 2.5;
		f->zoom_factor = 0.9;
		f->movement_speed = 0.03;
		f->max_iter = MAX_ITER;
		f->center_x = 0.0;
		f->center_y = 0.0;
		f->color_position = 1;
		f->palette = 0;
}

void	create_img(t_fractal *fractal)
{
	int bytes_per_pixel;
	int line_length;
	int endian;

	fractal -> img = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
	//Blindarlo
	fractal -> addr = mlx_get_data_addr(fractal -> img, &bytes_per_pixel, &line_length, &endian);
	printf("%d\n", line_length);
	printf("%d\n", WIDTH);
}


int		close_window(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->win);
	return (0);
}
