#ifndef FRACTOL_H

# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	char	*name;
	int		x;
	int		y;
	int		max_iter;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
}	t_fractal;

#define WIDTH 800
#define HEIGHT 800


void draw_julia(t_fractal *fractal);

#endif
