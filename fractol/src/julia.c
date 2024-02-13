#include "fractol.h"


int julia_escape_time(t_fractal f)
{
	int n;
	double tmp;

	n = 0;
    while (f.zr * f.zr + f.zi * f.zi <= 4.0 && n < f.max_iter) {
        tmp = f.zr * f.zr - f.zi * f.zi + f.cr;
        f.zi = 2 * f.zr * f.zi + f.ci;
        f.zr = tmp;
        n++;
    }
    return n;
}
void	my_mlx_pixel_put(t_fractal *f, int color)
{
	char	*dst;
	// WIDTH * 4 = line_length
	// Last 4 = bytes_per_pixel / 8
	dst = f->addr + (f->y * WIDTH * 4 + f->x * 4);
	*(unsigned int*)dst = color;
}

void draw_julia(t_fractal *f)
{
	int n;

	f -> x = -1;
	f -> y = -1;
	while (++f->x < WIDTH)
	{
		f->y = -1;
		while (++f->y < HEIGHT)
		{
			//Mapear coordenadas de px a complejos
			f -> zr = (f->x - f->center_x) * f->zoom / 200;
			f -> zi = (f->y - f->center_y) * f->zoom / 200;
			n = julia_escape_time(*f);
			int color;
			if (n == f -> max_iter) color = 0;
			else color = 0xFFFFFF * n / 100;
			my_mlx_pixel_put(f, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
