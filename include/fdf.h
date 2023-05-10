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

typedef struct S
{
	int		height;
	int		*width;
	int		**z_axis;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}t_ss;

void	test(t_ss *data, mlx_image_t* image);
void	bresenham(float x0, float y0, float x1, float y1, t_ss *data, mlx_image_t* image);
void	read_file(char *file, t_ss *parameters);
int		w_count(char *s, char set);

#endif