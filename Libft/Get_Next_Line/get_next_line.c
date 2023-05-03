/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 21:25:47 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/04/03 17:32:30 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*before_n(char *str)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc((i + 2) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*after_n(char *str)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc((ft_strlen_gnl(str) - i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	if (str[i])
		i++;
	while (str[i])
	{
		temp[j] = str[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*buff_until_n(char *str, int fd)
{
	char	*buff;
	int		red;

	red = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (red && !ft_strchr_gnl(str, '\n'))
	{
		red = read(fd, buff, BUFFER_SIZE);
		if (red > 0)
		{
			buff[red] = '\0';
			str = ft_strjoin_gnl(str, buff);
		}
		if (red == -1)
		{
			if (str)
				free (str);
			free (buff);
			return (NULL);
		}
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (read (fd, NULL, 0) == -1)
		return (NULL);
	str = buff_until_n(str, fd);
	if (!str || str[0] == '\0')
	{
		// free (str);
		return (NULL);
	}
	res = before_n(str);
	str = after_n(str);
	return (res);
}

// int	main(void)
// {
// 	int fd;
// 	int	i;

// 	fd = open("42.fdf", O_RDONLY, 0644);
// 	if ( fd == -1)
// 	{
// 		puts("cant open");
// 		exit(1);
// 	}
// 	if (fd == 0)
// 	{
// 		puts("end");
// 		exit(1);
// 	}
// 	else
// 	{
// 		puts("works");
// 	}
// 	i = 1;
// 	while (i < 12)
// 	{
// 		char *line = get_next_line(fd);
// 		printf("%s", line);
// 	// printf("%sA", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }
