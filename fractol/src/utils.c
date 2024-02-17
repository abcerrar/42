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

void	init_fractal_values(t_fractal *f)
{
		f->zoom = 2.5;
		f->zoom_factor = 0.9;
		f->movement_speed = 0.03;
		if (ft_strncmp(f->name, "j", 2) == 0)
		{
			f->cr = -0.7;
			f->ci = 0.27015;
		}
		if (ft_strncmp(f->name, "m", 2) == 0)
		{
			f->cr = -0.8;
			f->ci = 0.0;
		}
		f->center_x = 0.0;
		f->center_y = 0.0;
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
