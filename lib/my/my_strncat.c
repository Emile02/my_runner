/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** my_strncat
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    size_t dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}

