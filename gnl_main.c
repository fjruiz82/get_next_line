#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main()
{
	char	*line;
	int		i;

	int fd_1, fd_2, fd_3;
	fd_1 = open("prueba_1.txt", O_RDONLY);
	/*fd_2 = open("prueba_2.txt", O_RDONLY);
	fd_3 = open("prueba_3.txt", O_RDONLY);*/
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd_1);
		printf("%s", line);
		free(line);
		/*line = get_next_line(fd_2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd_3);
		printf("%s", line);
		free(line);*/
		i++;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}

/*int main (int *argv, char *argc)
{

}*/