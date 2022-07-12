#include <stdio.h>
#include <unistd.h>

void read_from_fd (int fd)
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
    }
}

char *get_next_line (int fd)
{

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
        printf("%s", line); // Se omite cada \n pq gnt se supone lo incluye ne cada línea.
    }
    fd = close(fd);
}   return (0);