/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:51 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/31 08:57:02 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reserve_line(char *reserved)
{
	char	*line;
	int		i;

	i = 0;
	if (!reserved[i])
		return (0);
	while (reserved[i] && reserved[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
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
	int		j;
	char	*saved;

	i = 0;
	while (reserved[i] && reserved[i] != '\n')
		i++;
	if (!reserved[i])
	{
		free(reserved);
		return (0);
	}
	saved = (char *)malloc(ft_strlen(reserved) - i + 1);
	if (!saved)
		return (0);
	i++;
	j = 0;
	while (reserved[i])
		saved[j++] = reserved[i++];
	saved[j] = '\0';
	free(reserved);
	return (saved);
}

char	*reading_fd(int fd, char *reserved)
{
	ssize_t	char_read;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	char_read = 1;
	while (!ft_strchr(reserved, '\n') && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(reserved);
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
	static char	*reserved[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	reserved[fd] = reading_fd(fd, reserved[fd]);
	if (!reserved[fd])
		return (0);
	line = reserve_line(reserved[fd]);
	reserved[fd] = save_rest(reserved[fd]);
	return (line);
}
