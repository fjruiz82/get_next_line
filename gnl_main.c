#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		i;
	char	*line;
    
}

int	main(void)
{
	int fd;

	fd = open("/Users/fruiz-ca/Documents/02_gnl/pruebas.txt", O_RDONLY);
	get_next_line(fd);
	printf("%s", get_next_line);
	return (0);
}