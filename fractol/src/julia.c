#include "fractol.h"


void	re_render(t_fractal *f)
{
	if (ft_strncmp(f->name, "j", 2) == 0 || ft_strncmp(f->name, "m", 2) == 0)
		draw_fractal(f);
	if (ft_strncmp(f->name, "s", 2) == 0)
	{
		t_point a = (t_point){WIDTH / 2 + f->center_x, 100 - f->center_y}; 
		t_point b = (t_point){100 + f->center_x, HEIGHT - 100 - f->center_y}; 
		t_point c = (t_point){WIDTH - 100 + f->center_x, HEIGHT - 100 - f->center_y}; 
		/*
		t_point a, b, c;
		a.x = (a.x - f->center_x) * f->zoom + f->center_x;
	    a.y = (a.y - f->center_y) * f->zoom + f->center_y;
		b.x = (b.x - f->center_x) * f->zoom + f->center_x;
		b.y = (b.y - f->center_y) * f->zoom + f->center_y;
		c.x = (c.x - f->center_x) * f->zoom + f->center_x;
		c.y = (c.y - f->center_y) * f->zoom + f->center_y;
		*/
		mlx_clear_window(f->mlx, f->win);
	    draw_sierpinski(f, a, b, c, (int)f->cr);
	}
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



