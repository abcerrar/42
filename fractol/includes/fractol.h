#ifndef FRACTOL_H

# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	char	*name;
	int		x;
	int		y;
	int		max_iter;
	double	center_x;
	double	center_y;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	zoom;
}	t_fractal;

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 60


void draw_julia(t_fractal *fractal);

#endif
