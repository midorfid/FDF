/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 18:04:48 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/05/10 16:49:18 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

float	maks(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	module(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	bresenham(float x0, float y0, float x1, float y1, t_ss *data, mlx_image_t* image)
{
	float		x_step;
	float		y_step;
	float		max;
	int			zoom = 10;
	int			z;
	int			z1;

	z = data->z_axis[(int)y0][(int)x0];
	z1 = data->z_axis[(int)y1][(int)x1];
	// isometric(&x0, &y0, z);
	x0 *= zoom;
	x1 *= zoom;
	y0 *= zoom;
	y1 *= zoom;
	x_step = x1 - x0;
	y_step = y1 - y0;
	data->color = (z || z1) ? 0xffffff : 0xffffff;
	max = maks(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	while (x0 != x1 + 1
	{
		mlx_put_pixel(image, x0, y0, data->color);
		x0 += x_step;
		y0 += y_step;
	}
}

// void	test(t_ss *data, mlx_image_t* image)
// {
// 	float x0 = 1.0;
// 	float x1 = 3.0;
// 	float y0 = 1.0;
// 	float y1 = 3.0;
// 	bresenham(110, 110, 200, 200, data, image);
// }


//mnukhit
	// int			min_x;
	// int			max_x;
	// int			min_y;
	// int			max_y;
	
// if (x0 >= x1)
// 	{
// 		min_x = x1;
// 		max_x = x0;
// 	}
// 	else 
// 	{
// 		min_x =x0;
// 		max_y = x1;
// 	}
// 	if (y0 >= y1)
// 	{
// 		min_y = y1;
// 		max_y = y0;
// 	}
// 	else 
// 	{
// 		min_y = y0;
// 		max_y = y1;
// 	}
	
// 	int i = 0;
// 	int j;

// 	while (i >= min_x && i <= max_x)
// 	{
// 		j = 0;
// 		while (j >= min_y && j <= max_y)
// 		{
// 			if ((i - min_x)/(j - min_y) == x_step/y_step)
// 				mlx_put_pixel(image, x0, y0, data->color);
// 			j++;
// 		}
// 		i++;
// 	}
