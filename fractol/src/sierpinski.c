#include "fractol.h"

void draw_triangle(t_fractal *f, t_point a, t_point b, t_point c) {
    // Dibuja un triángulo definido por los puntos a, b y c
	draw_line(f->mlx, f->win, a, b, get_color(f) * 50);
	draw_line(f->mlx, f->win, b, c, get_color(f) * 50);
	draw_line(f->mlx, f->win, c, a, get_color(f) * 50);
}

void draw_sierpinski(t_fractal *f, t_point a, t_point b, t_point c, int depth)
{
    t_point mid_ab, mid_bc, mid_ca;
	
	if (f->cr < 0)
		f->cr = 0;
	if (depth <= 0)
		draw_triangle(f, a, b, c);
	else
	{
        mid_ab.x = (a.x + b.x) / 2;
        mid_ab.y = (a.y + b.y) / 2;
        mid_bc.x = (b.x + c.x) / 2;
        mid_bc.y = (b.y + c.y) / 2;
        mid_ca.x = (c.x + a.x) / 2;
        mid_ca.y = (c.y + a.y) / 2;
		draw_sierpinski(f, a, mid_ab, mid_ca, depth - 1);
		draw_sierpinski(f, mid_bc, b, mid_ab, depth - 1);
		draw_sierpinski(f, mid_bc, mid_ca, c, depth - 1);
	}

}

/*
void draw_sierpinski(t_fractal *f) {
    t_point mid_ab, mid_bc, mid_ca;
	int i;

	mlx_clear_window(f->mlx, f->win);
	//Using f->cr as DEPTH
	i = f->cr;

	t_point a = {WIDTH / 2 + f->center_x, 100 - f->center_y}; 
	t_point b = {100 + f->center_x, HEIGHT - 100 - f->center_y}; 
	t_point c = {WIDTH - 100 + f->center_x, HEIGHT - 100 - f->center_y}; 

	draw_triangle(f, a, b, c);
    while (i-- > 0) {
        // Calcula los puntos medios de cada lado del triángulo
        mid_ab.x = (a.x + b.x) / 2;
        mid_ab.y = (a.y + b.y) / 2;
        mid_bc.x = (b.x + c.x) / 2;
        mid_bc.y = (b.y + c.y) / 2;
        mid_ca.x = (c.x + a.x) / 2;
        mid_ca.y = (c.y + a.y) / 2;

        // Dibuja los triángulos internos
        draw_triangle(f, mid_ab, mid_bc, mid_ca);

        // Actualiza los vértices para el siguiente nivel de detalle
        b = mid_ab;
        c = mid_bc;
        a = mid_ca;
    }
}
*/
