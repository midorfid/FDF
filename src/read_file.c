/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 17:49:20 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/05/10 17:19:36 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <string.h>

int	get_height(char *file)
{
	int		height;
	int		fd;
	// char	*temp;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	*get_width(char *file)
{
	int		*width;
	int		fd;
	char	*temp;

	fd = open(file, O_RDONLY, 0);
	width = 0;
	temp = get_next_line(fd);
	width = w_count(temp, ' ');
	free(temp);
	free (get_next_line(fd));
	free (get_next_line(fd));
	close(fd);
	return (width);
}

void	fill_z_axis_line(char *line, int	*z_axis)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_split(line, ' ');
	while (split[++i])
	{
		z_axis[i] = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split);
}

void	fill_z_axis(char *file, t_ss *data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = -1;
	fd = open(file, O_RDONLY, 0);
	while (++i < data->height)
	{
		line = get_next_line(fd);
		// ft_printf("yyyy:%d\n", strlen(line));
		fill_z_axis_line(line, data->z_axis[i]);
		free(line);
	}
	close(fd);
}

void	read_file(char *file, t_ss *data)
{
	data->height = get_height(file);
	data->width = get_width(file);
	data->z_axis = malloc((sizeof(int *)) * (data->height + 1));
	int	i = -1;
	while (++i < data->height)
		data->z_axis[i] = malloc(4 * (data->width + 1));
	fill_z_axis(file, data);
	data->z_axis[i] = NULL;
}
