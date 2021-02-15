/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/

#include <string.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (str[0] != '\0') {
        while (to_find[i] != str[0]) {
            i++;
        }
        if (to_find[i] == str[0]) {
            my_strstr(str + 1, to_find);
            my_putchar(str[i]);
        }
        return (str);
    }
}
