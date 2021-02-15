/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 97 && str[i] <= 122) {
        str[i] = str[i] - 32;
    }

    while (str[i] != '\0') {
        if ((str[i - 1] >= 23 && str[i - 1] <= 47) || str[1 - i] <= ';') {
            if (str[i] <= 'z' && str[i] >= 'a') {
                str[i] = str[i] - 32;
            }
        }
        i++;
    }
    return (str);
}
