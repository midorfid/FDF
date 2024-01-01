#include "../include/fdf.h"

void    draw_picture(t_map *map, mlx_image_t *image){
	int x,y = 0;
	
	while (y != map->height && y + 1 != map->height)
	{
		x = 0;
		while (x != map->width && x + 1 != map->width)
		{
			if (x < map->width - 1)
				// bresenham(x, y, x + 1, y, data, image);
			if (y < map->height - 1)
				// bresenham(x, y, x, y + 1, data, image);
			x++;
		}
		y++;
	}
	// // edge lines
	x = 0;
	while (x != map->width && x + 1 != map->width)
	{
		// bresenham(x, y, x + 1, y, data, image);
		x++;
	}
	y = 0;
	while (y != map->height && y + 1 != map->height)
	{
		// bresenham(x, y, x, y + 1, data, image);
		y++;
	}
}
