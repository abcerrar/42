#include "fractol.h"

#define MAX_ITER 100
typedef struct s_fractal{
	char *name;
	int x;
	int y;
	double cx;
	double cy;
	int max_iterations;
}	t_fractal; 

int julia_escape_time(double cr, double ci, double zr, double zi)
{
	int n;
	int max_iter;
	double tmp;

	max_iter = 100;
	n= 0;
    while (zr*zr + zi*zi <= 4 && n < max_iter) {
        tmp = zr*zr - zi*zi + cr;
        zi = 2*zr*zi + ci;
        zr = tmp;
        n++;
    }
    return n;
}

void draw_julia(void *mlx, void *win, double cr, double ci, int dimensions[])
{
	int	x;
	int	y;
	int n;
	double zr;
	double zi;

	x = -1;
	y = -1;

	while (++x < dimensions[0])
	{
		y = -1;
		while (++y < dimensions[1])
		{
			//Mapear coordenadas de px a complejos
			zr = (x - dimensions[0] / 2.0) / 200;
			zi = (y - dimensions[1] / 2.0) / 200;
//			zr = (x - dimensions[0] / 2) * 4.0 / dimensions[0];
//          zi = (y - dimensions[1] / 2) * 4.0 / dimensions[1];
			n = julia_escape_time(cr, ci, zr, zi);
//          int color = (n == 100) ? 0 : 0xFFFFFF * n / 100;
			int color;
			if (n == 100) color = 0x00FF0000;
			else color = 0x0000FF00;
			mlx_pixel_put(mlx, win, x, y, color);
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
