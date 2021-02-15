/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        if (src[i] == '\0')
            return (0);
        else
            dest[i] = src[i];
    }
    dest[i] == '\0';
    return (dest);
}
