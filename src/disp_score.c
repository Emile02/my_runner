/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** score
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void score(window_t *mainwindow)
{
    int pts = 0;
    while (sfRenderWindow_isOpen(mainwindow->window)) {
        pts += 1;
        sleep (1);
        my_put_nbr(pts);
    }
}