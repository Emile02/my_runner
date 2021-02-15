/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] < 20)
            return (0);
    }
    return (1);
}
