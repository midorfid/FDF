/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashevchu <ashevchu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 21:12:40 by ashevchu      #+#    #+#                 */
/*   Updated: 2023/03/30 20:51:21 by ashevchu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

size_t	ft_strlen_gnl(const char *s);

char	*ft_strjoin_gnl(char *s1, char *s2);

char	*ft_strchr_gnl(const char	*str, int s);

char	*before_n(char *str);

char	*after_n(char *str);

char	*buff_until_n(char *str, int fd);

char	*get_next_line(int fd);

char	*ft_strdup_gnl(char *s1);

#endif