/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** open maps
*/

#include "../include/my_runner.h"
#include "../include/my.h"

char *open_map(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    int reader;
    char *str;
    str = malloc(sizeof(char) * (501));
    reader = read(fd, str, 500);
    str[500] = '\0';
    if (!(argc == 2 && fd != -1 && reader != -1))
        return (NULL);
    close(fd);
    return (str);
}