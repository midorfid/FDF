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
#include "../include/line.h"
#include "../MLX42/include/MLX42/MLX42.h"

t_color	init_color(t_points p1, t_points p2, int delta[2]){
	const uint8_t		*p1_color = (uint8_t*)&p1.color;
	const uint8_t		*p2_color = (uint8_t*)&p2.color;
	t_color					color;
	int						i;

	ft_bzero(&color, sizeof(t_color));
	if(p1.color == p2.color){
		color.orginal = p1.color;
		return (color);
	}
	if(delta[X] < delta[Y])
		color.axis = Y;
	else
		color.axis = X;
	color.alt = 1;
	i = 0;
	while(i < 4){
		color.change[i] = (double)((int)p2_color[i] - \
				(int)p1_color[i]) / delta[color.axis];
		color.current[i] = p1_color[i];
		++i;
	}
	return(color);
}

void	add_color(t_color *color){
	int	i;

	if(!color->alt)
		return ;
	i = 0;
	while(i < 4){
		color->current[i] += color->change[i];
		++i;
	}
}

int		get_color(t_color *color){
	int 	i;
	int		result;
	uint8_t *_result;

	if(!color->alt)
		return(color->orginal);
	_result = (uint8_t *)&result;
	i = 0;
	while(i < 4){
		_result[i] = color->current[i];
		++i;
	}
	return(result);
}

t_line init_line(t_points p1, t_points p2){
	t_line line;
	
	line.start[X] = p1.cords[X];
	line.start[Y] = p1.cords[Y];
	line.end[X] = p2.cords[X];
	line.end[Y] = p2.cords[Y];
	line.delta[X] = abs(line.end[X] - line.start[X]);
	line.sign[X] = 1;
	if(line.end[X] < line.start[X])
		line.sign[X] = -1;
	line.delta[Y] = abs(line.end[Y] - line.start[Y]);
	line.sign[Y] = 1;
	if(line.end[Y] < line.start[Y])
		line.sign[Y] = -1;
	line.error[0] = line.delta[X] + (-line.delta[Y]);
	line.color = init_color(p1, p2, line.delta);
	return(line);
}

void draw_line(t_points p1, t_points p2, \
		void (*plotf)(int, int, int, void *), void *data){
	t_line line;

	line = init_line(p1, p2);
	while(1){
		plotf(line.start[X], line.start[Y], get_color(&line.color), data);
		if(line.start[X] == line.end[X] && line.start[Y] == line.end[Y])
			break ;
		line.error[1] = line.error[0] * 2;
		if(line.error[1] >= -line.delta[Y]){
			if(line.color.axis == X)
				add_color(&line.color);
			line.error[0] -= line.delta[Y];
			line.start[X] += line.sign[X];
		}
		if(line.error[1] <= line.delta[X]){
			if(line.color.axis == Y)
				add_color(&line.color);
			line.error[0] += line.delta[X];
			line.start[Y] += line.sign[Y];
		}
	}
}
