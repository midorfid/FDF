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
# include <stdio.h>
# include "../Libft/include/libft.h"
# include "../Libft/get_next_line/include/get_next_line.h"
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
	t_map 				*map;
	mlx_t				*mlx;
	mlx_image_t			*img[2];
	mlx_image_t			*text_img[4];
	int					update;
	int					img_idx[2];
	double				scale;
	double				map_scale;
	double				x_offset;
	double				y_offset;
	double				z_scale;
	int					projection;
	int					current_img;
}t_fdf;

void    error_msg_exit(char *error, int error_code);
void    *alloc_or_perror(void *ptr);
void    exit_if_true(bool status);

int		ft_atoi_save(const char *str, int *num);
char	*ft_strndup(char *str, size_t n);

t_map	*parse_map(char *filename);
t_map	*dup_map(t_map *map);
void    destroy_map(t_map *map);
t_map	*init_map();

void    map_apply_offset(t_map *map, double offset[3]);
void    map_apply_scale(t_map *map, double scale[3]);
void    map_apply_iso(t_map *map);

void    plot_point(mlx_image_t *img, t_map *map);
void	draw_line(t_points p1, t_points p2, \
		void (*plotf)(int, int, int, void *), void *data);
void	plot_img(mlx_image_t *img, t_map *map);

void	destroy_fdf(t_fdf *fdf);
t_fdf   *init_fdf(int w_height, int w_width, char *filename);

void    resize_hook(int32_t width, int32_t height, void *input_data);
void    key_hook(mlx_key_data_t keydata, void *input_data);
void    loop_hook(void *input_data);

void	free_row(char **row);
int		w_count(char *s, char set);

void    update_screen(t_fdf *data);
void    start_renderloop_fdf(t_fdf *fdf);
#endif