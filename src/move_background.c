/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** move_parallax
*/

#include "../include/my_runner.h"
#include "stdarg.h"

gameobject_t *set_parallax(char *path_to_png, float x, float speed)
{
    gameobject_t *tmp = malloc(sizeof(gameobject_t));

    tmp->speed = speed;
    tmp->x = x;
    tmp->Texture = sfTexture_createFromFile(path_to_png, NULL);
    tmp->sprite = sfSprite_create();
    sfSprite_setTexture(tmp->sprite, tmp->Texture, sfFalse);
    sfSprite_setPosition( tmp->sprite, (sfVector2f) {x, 0});
    return (tmp);
}

void move_parallax(window_t *mainwindow)
{
    for (int i = 0; i < 8; i++) {
        sfRenderWindow_drawSprite
        (mainwindow->window, mainwindow->tab[i]->sprite, NULL);
        sfSprite_setPosition
        (mainwindow->tab[i]->sprite, (sfVector2f) {mainwindow->tab[i]->x -=
        (2 * (mainwindow->tab[i]->speed / 2)) , 0});
        if (mainwindow->tab[i]->x == -1920) {
            sfRenderWindow_drawSprite
            (mainwindow->window, mainwindow->tab[i]->sprite, NULL);
            sfSprite_setPosition
            (mainwindow->tab[i]->sprite,
            (sfVector2f) {mainwindow->tab[i]->x = 1920, 0});
        }
    }
}