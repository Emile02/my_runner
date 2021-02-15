/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** destroy
*/

#include "../include/my_runner.h"

void destroy(window_t *mainwindow)
{
    int i = 0;
    sfSprite_destroy(mainwindow->tab[i]->sprite);
    sfTexture_destroy(mainwindow->tab[i]->Texture);
}