/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 19:47:23 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/05/10 16:40:28 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
#include <string.h>
#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;
/*open, close, read, write,
malloc, free, perror,
strerror, exit*/
// void ft_randomize(void* param)
// {
// 	for (int32_t i = 0; i < image->width; ++i)
// 	{
// 		for (int32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_ss	*data;
	// int		fd;

	// fd = open("../test_maps/42.fdf", O_RDONLY, 0);
	// ft_printf("yyyy:%d\n", strlen(get_next_line(fd)));
	// close(fd);
	// return (0);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// Gotta error check this stuff
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);	
	}
	if (!(image = mlx_new_image(mlx, 512, 512)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// test(data, image);
	// bresenham(110, 110, 110, 110, data, image);

	// mlx_put_pixel(image, 100, 100, 0xffffff);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);

	data = malloc(sizeof(t_ss));
	read_file(argv[1], data);
	int x,y = 0;
	
	while (y != data->height && y + 1 != data->height)
	{
		x = 0;
		while (x != data->width && x + 1 != data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data, image);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data, image);
			x++;
		}
		y++;
	}
	// // edge lines
	x = 0;
	while (x != data->width && x + 1 != data->width)
	{
		bresenham(x, y, x + 1, y, data, image);
		x++;
	}
	y = 0;
	while (y != data->height && y + 1 != data->height)
	{
		bresenham(x, y, x, y + 1, data, image);
		y++;
	}
	// edge lines
	// bresenham(0, 0, 10, 10, data, image);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// free(data);
	// system("leaks a.out");
	return (EXIT_SUCCESS);
}
