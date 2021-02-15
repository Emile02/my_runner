/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 2)
        return (nb * nb);

    if (nb == 0 || nb == 1)
        return (1);

    if (p > 0)
        return (0);
    p = p - 1;
    nb = nb * my_compute_power_rec(nb , p - 1);

    return (nb);
}