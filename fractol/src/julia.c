#include "fractol.h"

int julia_escape_time(t_fractal f)
{
	int n;
	double tmp;

	n= 0;
    while (f.zr * f.zr + f.zi * f.zi <= 4 && n < f.max_iter) {
        tmp = f.zr * f.zr - f.zi * f.zi + f.cr;
        f.zi = 2 * f.zr * f.zi + f.ci;
        f.zr = tmp;
        n++;
    }
    return n;
}

void draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;
	int n;

	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			//Mapear coordenadas de px a complejos
			fractal -> zr = (x - WIDTH / 2.0) * 0.8 / 200;
			fractal -> zi = (y - HEIGHT / 2.0) * 0.8 / 200;
			n = julia_escape_time(*fractal);
//          int color = (n == 100) ? 0 : 0xFFFFFF * n / 100;
			int color;
			if (n == 100) color = 0x00FF0000;
			else color = 0x0000FF00;
			mlx_pixel_put(fractal -> mlx, fractal -> win, x, y, color);
		}
	}
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
