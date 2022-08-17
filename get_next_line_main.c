#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 1000

char read_from_fd (int fd)
{
    int i;
    char *buf;

    buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);

    i = 0;
    while (fd > 0)
    {
        i = read(fd, buf, BUFFER_SIZE);
        if (i == -1)
        {

        }
    }
    return (*buf);
}

char *get_next_line (int fd)
{
    char *buf;
    static char *tmp;
    size_t nbytes;
    //size_t BUFFER_SIZE;
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
    return (0);
}


int main (int argc, char **argv)
{
    int fd;
    char *line;

    (void)argc; //casteo para evitar warnings del compilador.

    fd = open(argv[1], O_RDONLY); // abre el archivo dado como un argumento 
    line = ""; // inicializa esta variable para poder usarla en el siguiente bucle
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line); // Se omite cada \n pq gnl se supone lo incluye en cada línea.
    }
    fd = close(fd);
    return (0);
}
