/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file for make my rocks coming
*/

#include "../include/my_runner.h"
#include "../include/my.h"

gameobject_t **init_obstacle(gameobject_t **obstacle, int nb)
{
    for (int i = 0; i < nb; i++)
    {
        obstacle[i] = set_obstacle(i);
    }
    return (obstacle);
}

gameobject_t *set_obstacle(int i)
{
    gameobject_t *obstacle = malloc(sizeof(gameobject_t));
    obstacle->Texture = sfTexture_createFromFile
    ("assets/png/stone01.png", NULL);
    obstacle->sprite = sfSprite_create();
    sfSprite_setTexture(obstacle->sprite, obstacle->Texture, sfTrue);
    obstacle->vector.x = i * 128;
    obstacle->vector.y = 713;
    obstacle->speed = -0.5;

    return (obstacle);
}

int pop_rock(char *str, gameobject_t **obstacle, window_t *mainwindow)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '2') {
            sfSprite_setPosition(obstacle[i]->sprite,
            (sfVector2f) {obstacle[i]->vector.x -= 4, 713});
            sfRenderWindow_drawSprite
            (mainwindow->window, obstacle[i]->sprite, NULL);
        }
        if (str[i] == '1')
            sfSprite_setPosition(obstacle[i]->sprite,
            (sfVector2f) {obstacle[i]->vector.x -= 4, 713});
    }
    return (0);
}

void collide(gameobject_t *runner, gameobject_t *obstacle, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '2')
        {
            if (runner->x >= obstacle->x
            && runner->vector.x <= obstacle->vector.x + 128
            && runner->vector.y >= obstacle->vector.y
            && runner->vector.y <= obstacle->vector.y + 128) {
            }
        }
    }
}