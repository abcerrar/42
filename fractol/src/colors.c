#include "fractol.h"

int	get_palette(int palette, int color)
{
	int palettes[][22] = 
	{
		{
			//Green
			0x000100, 0x000200, 0x000300, 0x000400,
			0x000400, 0x000300, 0x000200, 0x000100,
			//Red
			0x020000, 0x030000, 0x040000,// 0x040000,
			0x040000, 0x030000, 0x020000, 0x010000,
			//Blue
			0x000002, 0x000003, 0x000004,// 0x000004,
			0x000004, 0x000003, 0x000002, 0x000001
		},
			//Black and white
		{
			0x010101, 0x020202, 0x030303, 0x040404,
			0x040404, 0x030303, 0x020202, 0x010101,
			0x020202, 0x030303, 0x040404,
			0x040404, 0x030303, 0x020202, 0x010101,
			0x020202, 0x030303, 0x040404,
			0x040404, 0x030303, 0x020202, 0x010101
		}
	};
	
	return (palettes[palette][color]);
}

int	get_color(t_fractal *f)
{
	if (f->palette == 1)
		return (0x050000);
	if (f->palette == 0)
		return (0x000500);
	if (f->palette == 2)
		return (0x000005);
	//printf("Palette: %d\n", f->palette);
	//printf("Color position: %d\n", f->color_position);
	
	int palette_size = 22;

	if (f->color_position >= palette_size)
		f->color_position = 1;
	if (f->color_position <= 0)
		f->color_position = palette_size - 1;

	return (get_palette(f->palette - 3, f->color_position));
}
