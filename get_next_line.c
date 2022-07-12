/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:15:24 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/19 12:08:50 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
    char *buf;
    static char *tmp;
    size_t nbytes;
    size_t BUFFER_SIZE;
    int text_len;
    int i;


    buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);

    text_len = read (fd, buf, BUFFER_SIZE);
    i = 0;
    while (text_len != 0)
    {
        if (text_len == -1)
        {
            free (buf);
            return (0);
        }
        i++;

    }

    
}
