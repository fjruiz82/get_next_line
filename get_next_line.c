/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:15:24 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/17 13:30:13 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1000000

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] && str[i] != (char)c)
		str++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*concat;
	unsigned int	i;

	concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		concat[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		concat[i] = *s2;
		i++;
		s2++;
	}
	concat[i] = '\0';
	return (concat);
}





char	*reserve_line(char *reserved)
{
	char	*line;
	int		i;

	/*int len;
    len = strlen ()*/
	i = 0;
    if (!reserved[i])
        return (0);
	while (reserved[i] && reserved[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
        return (0);
        i = 0;
    while (reserved[i] && reserved[i] != '\n')
    {
		line[i] = reserved[i];
		i++;
	}
	if (reserved[i] == '\n')
	{
		line[i] = reserved[i];
        i++;
	}
	reserved[i] = '\0';
	return (line);
}

char	*save_rest(char *reserved)
{
    int i;
    int c;
    char *s;

    i = 0;
    while (reserved[i] && reserved[i] != '\n')
        i++;
    if (!reserved[i])
    {
        free(reserved);
        return (0);
    }
    s = (char *)malloc(sizeof(char) * (ft_strlen(reserved) - i + 1));
    if (!s)
        return(0);
    i++;
    c = 0;
    while (reserved[i])
        s[c++] = reserved[i++];
    s[c] = '\0';
    free(reserved);
    return (s);
}
char	*reading_fd(int fd, char *reserved)
{
	ssize_t	char_read;
	char	*buf;
    
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (0);
    char_read = 1;
	while (!ft_strchr(reserved, '\n') && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[char_read] = '\0';
		reserved = ft_strjoin(reserved, buf);
	}
	free(buf);
	return (reserved);
}

char	*get_next_line(int fd)
{
	static char	*reserved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reserved = reading_fd(fd, reserved);
	if (!reserved)
		return (0);
	line = reserve_line(reserved);
	reserved = save_rest(reserved);
	return (line);
}





int	main(void)
{
	char *line;
	int i;
	int fd_1, fd_2, fd_3;
	fd_1 = open("/prueba_1.txt", O_RDONLY);
	fd_2 = open("/prueba_2.txt", O_RDONLY);
	fd_3 = open("/prueba_3.txt", O_RDONLY);

	i = 1;
	while (i < 3)
	{
		line = get_next_line(fd_1);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd_2);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd_3);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}