/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 18:04:48 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/04/25 17:59:59 by ashevchu      ########   odam.nl         */
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

void	isometric(float *x0, float *y0, int z)
{
	*x0 = (*x0 - *y0) * cos(0.8);
	*y0 = (*x0 + *y0) * sin(0.8) - z;
}

void	bresenham(float x0, float y0, float x1, float y1, t_ss *data, mlx_image_t* image)
{
	float		x_step;
	float		y_step;
	float		max;
	int			zoom = 20;
	int			z;
	int			z1;
	
	z = data->z_axis[(int)y0][(int)x0];
	z1 = data->z_axis[(int)y1][(int)x1];
	x0 *= zoom;
	x1 *= zoom;
	y0 *= zoom;
	y1 *= zoom;
	x_step = x1 - x0;
	y_step = y1 - y0;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	max = maks(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	isometric(&x0, &y0, z);
	int i = 0;
	while (x0 != x1 + 1 && y0 != y1 + 1)
	{
		mlx_put_pixel(image, x0, y0, data->color);
		x0 += x_step;
		y0 += y_step;
		i++;
		if (x0 > data->width || y0 > data->height || y0 < 0 || x0 < 0)
			break ;
	}
}
