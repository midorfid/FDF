/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 19:30:09 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/30 22:40:57 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	w_count(char *s, char set)
{
	int		parts;
	int		found;

	parts = 0;
	while (*s)
	{
		found = 0;
		while (*s && *s++ != set)
			found = 1;
		while (*s && *s == set)
			s++;
		if (found)
			parts++;
	}
	return (parts);
}
