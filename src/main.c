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

//static mlx_image_t* image;
/*open, close, read, write,
malloc, free, perror,
strerror, exit*/

int	main(int argc, char **argv){
	t_fdf *fdf;

	if(argc != 2){
		ft_putendl_fd("fdf : invalid input", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	fdf = init_fdf(1000, 1000, argv[1]);
	mlx_loop(fdf->mlx);
	destroy_fdf(fdf);

	return(EXIT_SUCCESS);
}
