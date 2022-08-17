/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:16:16 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/17 11:31:43 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
