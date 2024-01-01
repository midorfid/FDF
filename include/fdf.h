/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 20:10:55 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/05/10 17:17:40 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define X 0
# define Y 1
# define Z 2
# define ISO 0

typedef	struct s_points
{
	double	cords[3];
	int		color;

}t_points;


typedef struct s_map
{
	size_t		column;
	size_t		row;
	t_points	*point;

}t_map;

typedef struct s_fdf
{
	t_map *map;
	//projection
	//zoom
	//mlx_image

}t_fdf;

void	test(t_ss *data, mlx_image_t* image);
void	bresenham(float x0, float y0, float x1, float y1, t_ss *data, mlx_image_t* image);
void	read_file(char *file, t_ss *parameters);
int		w_count(char *s, char set);

#endif