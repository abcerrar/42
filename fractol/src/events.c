#include "fractol.h"

int raton(int button, int x, int y, t_fractal *f)
{
	//Calcular la coordenada compleja de la posicion del raton antes y despues del 
	//zoom y luego ajustar el centro a esas coordenadas.

	double	complex_x = f->center_x + (((double)x - WIDTH / 2) * (f->zoom / WIDTH));
	double	new_complex_x; 
	double	complex_y = f->center_y + (((double)y - HEIGHT / 2) * (f->zoom / HEIGHT));
	double	new_complex_y; 

	if (button == 4)
		f->zoom *= f->zoom_factor;
	if (button == 5)
		f->zoom /= f->zoom_factor;
	new_complex_x = f->center_x + (((double)x - WIDTH / 2) * (f->zoom / WIDTH));
	new_complex_y = f->center_y + (((double)y - HEIGHT / 2) * (f->zoom / HEIGHT));
	f->center_x += complex_x - new_complex_x;
	f->center_y -= complex_y - new_complex_y;
	draw_julia(f);
	return (0);
}

int key_release(int keycode, t_fractal *f)
{
	if (keycode == SHIFT)
		f->shift_pressed = 0;
	return (0);
}

void	init_julia_movements(t_fractal *f, int keycode)
{
	if (keycode == KEY_RIGTH)
		f->cr += 0.01;
	if (keycode == KEY_LEFT)
		f->cr -= 0.01;
	if (keycode == KEY_UP)
		f->ci += 0.01;
	if (keycode == KEY_DOWN)
		f->ci -= 0.01;
	
}

int key_press(int keycode, t_fractal *f)
{
	printf("keycode: %d\n", keycode);
	//	ZOOM
	if (keycode == PLUS)
		f->zoom *= f->zoom_factor;
	if (keycode == MINUS)
		f->zoom /= f->zoom_factor;
	//	MOVEMENT
	if (f->shift_pressed == 1)
		init_julia_movements(f, keycode);
	else
	{
		if (keycode == KEY_RIGTH)
			f->center_x += f->movement_speed * f->zoom;
		if (keycode == KEY_LEFT)
			f->center_x -= f->movement_speed * f->zoom;
		if (keycode == KEY_UP)
			f->center_y += f->movement_speed * f->zoom;
		if (keycode == KEY_DOWN)
			f->center_y -= f->movement_speed * f->zoom;
	}
	//	EXIT
	if (keycode == ESC)
		mlx_destroy_window(f -> mlx, f -> win);
	//	RESET
	if (keycode == RESET)
		init_fractal_values(f);
	draw_julia(f);
	if (keycode == SHIFT)
		f->shift_pressed = 1;
	return (0);
}

int raton_movimiento(int x, int y, t_fractal *fractal)
{
	return (0);
}
