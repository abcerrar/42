#include "fractol.h"

int	get_color(t_fractal *f)
{
	//Se pueden añadir diferentes paletas de colores.
	int palette[] = 
	{
		//Green
		0x000200, 0x000300, 0x000400, 0x000500,
		0x000400, 0x000300, 0x000200, 0x000100,
		//Red
		0x020000, 0x030000, 0x040000, 0x050000,
		0x040000, 0x030000, 0x020000, 0x010000,
		//Blue
		0x000002, 0x000003, 0x000004, 0x000005,
		0x000004, 0x000003, 0x000002, 0x000001
	};
	int palette_size = sizeof(palette) / sizeof(palette[0]);
	if (f->color_position == palette_size)
		f->color_position = 0;
	if (f->color_position == -1)
		f->color_position = palette_size - 1;

	return (palette[f->color_position]);
}
