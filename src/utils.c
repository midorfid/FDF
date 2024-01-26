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

size_t ft_strnlen(char *str, size_t maxlen){
	size_t i;

	i = 0;
	while(str[i] && i < maxlen)
		++i;
	return(i);
}

char *ft_strndup(char *str, size_t n){
	size_t	len;
	char	*res;

	len = ft_strnlen(str, n);
	res = malloc(len + 1);
	if(!res)
		return(res);
	res[len] = '\0';
	return(ft_memcpy(res, str, len));
}
