/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 21:06:20 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/30 20:52:45 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	char	*temp;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	temp = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (temp == NULL)
		return (NULL);
	while (s1[++i])
		temp[i] = s1[i];
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = '\0';
	free (s1);
	return (temp);
}

char	*ft_strchr_gnl(const char	*str, int c)
{
	size_t			i;
	char			*s;
	unsigned char	chr;

	i = 0;
	chr = c;
	s = (char *)str;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (chr == s[i])
			return (&s[i]);
		i++;
	}
	if (s[i] == chr)
		return (&s[i]);
	return (NULL);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (ptr);
	while (i >= 0)
	{
		ptr[i] = s1[i];
		i--;
	}
	return (ptr);
}
