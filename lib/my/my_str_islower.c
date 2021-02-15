/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    int i = 0;

    for (;str[i] != '\0'; i++) {
        if (str[i] >= 'a' || str[i] <= 'z')
            return (0);
    }
    return (1);
}
