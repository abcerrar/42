#include "fractol.h"

void fill_triangle2(t_fractal f, t_point a, t_point b, t_point c, int color)
{
	t_point top;
	t_point left;
	t_point rigth;

	if (a.y < b.y && a.y < c.y)
		top = a;
	else if (b.y < c.y)
		top = b;
	else
		top = c;
	if (a.x < b.x && a.x < c.x)
		rigth = a;
	else if (b.x < c.x)
		rigth = b;
	else
		rigth = c;
	if (a.x > b.x && a.x > c.x)
		left = a;
	else if (b.x > c.x)
		left = b;
	else
		left = c;
	while (rigth.x++ < left.x)
		draw_line(f.mlx, f.win, top, rigth, get_color(&f) * 50);

}

void draw_triangle(t_fractal *f, t_point a, t_point b, t_point c) {
	draw_line(f->mlx, f->win, a, b, get_color(f) * 50);
	draw_line(f->mlx, f->win, b, c, get_color(f) * 50);
	draw_line(f->mlx, f->win, c, a, get_color(f) * 50);
	fill_triangle2(*f, a, b, c, get_color(f));
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
