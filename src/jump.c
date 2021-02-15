/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** da jump
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void gestion_event(gameobject_t *runner)
{
    if (runner->speed == 0) {
    runner->gravity = 10;
    runner->speed = -65;
    }
}

void gestion_hitbox(gameobject_t *runner)
{
    if (runner->vector.y > 708)
    {
        runner->gravity = 0;
        runner->speed = 0;
        runner->vector.y = 708;
    }
}

void update(gameobject_t *runner, sfTime time)
{
    float elapsed = time.microseconds/1000000.0;
    runner->vector.y += runner->speed * elapsed;
    runner->speed += runner->gravity * elapsed;
    sfSprite_setPosition(runner->sprite, runner->vector);
    gestion_hitbox(runner);
}