#include "fractol.h"


void	re_render(t_fractal *f)
{
	if (ft_strncmp(f->name, "j", 2) == 0 || ft_strncmp(f->name, "m", 2) == 0)
		draw_fractal(f);
	if (ft_strncmp(f->name, "s", 2) == 0)
		draw_sierpinski(f);
}

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

void draw_fractal(t_fractal *f)
{
	int n;

	f->x = -1;
	f->y = -1;
	while (++f->x < WIDTH)
	{
		f->y = -1;
		while (++f->y < HEIGHT)
		{
			//Mapear coordenadas de px a complejos
			f->zr = f->center_x + (f->x - WIDTH / 2) * (f->zoom / WIDTH);
			f->zi = f->center_y - (f->y - HEIGHT / 2) * (f->zoom / HEIGHT);
			n = julia_escape_time(*f);
			int color;
			if (n == f->max_iter) color = 0;
			else color = get_color(f) * n;
			my_mlx_pixel_put(f, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}



void draw_triangle(t_fractal *f, t_point a, t_point b, t_point c) {
    // Dibuja un triángulo definido por los puntos a, b y c
	draw_line(f->mlx, f->win, a, b, get_color(f) * 50);
	draw_line(f->mlx, f->win, b, c, get_color(f) * 50);
	draw_line(f->mlx, f->win, c, a, get_color(f) * 50);
}

void draw_sierpinski(t_fractal *f) {
    t_point mid_ab, mid_bc, mid_ca;
	int i;

	//Using f->cr as DEPTH
	i = f->cr;

	f->a = (t_point){WIDTH / 2 + f->center_x, 100 + f->center_y}; 
	f->b = (t_point){100 + f->center_x, HEIGHT - 100 + f->center_y}; 
	f->c = (t_point){WIDTH - 100 + f->center_x, HEIGHT - 100 + f->center_y}; 
	mlx_clear_window(f->mlx, f->win);

	draw_triangle(f, f->a, f->b, f->c);
    while (i-- > 0) {
        // Calcula los puntos medios de cada lado del triángulo
        mid_ab.x = (f->a.x + f->b.x) / 2;
        mid_ab.y = (f->a.y + f->b.y) / 2;
        mid_bc.x = (f->b.x + f->c.x) / 2;
        mid_bc.y = (f->b.y + f->c.y) / 2;
        mid_ca.x = (f->c.x + f->a.x) / 2;
        mid_ca.y = (f->c.y + f->a.y) / 2;

        // Dibuja los triángulos internos
        draw_triangle(f, mid_ab, mid_bc, mid_ca);

        // Actualiza los vértices para el siguiente nivel de detalle
        f->b = mid_ab;
        f->c = mid_bc;
        f->a = mid_ca;
    }
}
