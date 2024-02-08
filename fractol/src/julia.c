#include "fractol.h"


int julia_escape_time(t_fractal f)
{
	int n;
	double tmp;

	n= 0;
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
			f -> zr = (f->x - WIDTH / 2.0) * f->zoom / 200;
			f -> zi = (f->y - HEIGHT / 2.0) * f->zoom / 200;
			n = julia_escape_time(*f);
//          int color = (n == 100) ? 0 : 0xFFFFFF * n / 100;
			int color;
			if (n == f -> max_iter) color = 0;
			else color = 0xFFFFFF * n / 100;
			my_mlx_pixel_put(f, color);
			//mlx_pixel_put(f -> mlx, f -> win, f->x, f->y, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
/*
int julia_escape_time(double cr, double ci, double zr, double zi) {
    int n = 0;
    while (zr*zr + zi*zi <= 4 && n < MAX_ITER) {
        double tmp = zr*zr - zi*zi + cr;
        zi = 2*zr*zi + ci;
        zr = tmp;
        n++;
    }
    return n;
}

void draw_julia_set(void *mlx, void *win, double cr, double ci) {
    for (int x = 0; x < 800; x++) {
        for (int y = 0; y < 600; y++) {
            // Mapeo de coordenadas de píxeles a números complejos
            double zr = (x - 400) / 200.0;
            double zi = (y - 300) / 200.0;
            int n = julia_escape_time(cr, ci, zr, zi);
            int color = (n == MAX_ITER) ? 0 : 0xFFFFFF * n / MAX_ITER;
            mlx_pixel_put(mlx, win, x, y, color);
        }
    }
}
*/
