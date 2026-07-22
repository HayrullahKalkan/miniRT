
#include "../mini_rt.h"


void parse_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == 'A')
            printf("Ambient light\n");
        else if (line[i] == 'C')
            printf("Camera\n");
        else if (line[i] == 'L')
            printf("Light\n");
        else if (line[i] == 's' && line[i + 1] == 'p')
        {
            printf("Sphere\n");
            i++;
        }
        else if (line[i] == 'p' && line[i + 1] == 'l')
        {
            printf("Plane\n");
            i++;
        }
        else if (line[i] == 'c' && line[i + 1] == 'y')
        {
            printf("Cylinder\n");
            i++;
        }
        i++;
    }
}


void parser(int fd)
{
    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
        parse_line(line);
        free(line);
    }
}