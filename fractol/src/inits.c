#include "fractol.h"

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
	/*
	f->a = NULL;
	f->b = NULL;
	f->c = NULL;
	*/
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
		if (ft_strncmp(f->name, "s", 2) == 0)
			f->movement_speed = 3;
}
