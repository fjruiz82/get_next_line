#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char get_next_line(int fd);

int main ()
{
    int fd;

    fd = open ("/Users/fruiz-ca/Documents/02_gnl/pruebas.txt", O_RDONLY);
    printf("%s",get_next_line);
    return (0);
}