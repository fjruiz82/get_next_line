/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:15:24 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/18 09:40:30 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reserve_line(char *reserved)
{
	char	*line;
	int		i;

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
	line[i] = '\0';
	return (line);
}

char	*save_rest(char *reserved)
{
	int		i;
	int		c;
	char	*s;

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
		return (0);
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
