/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** time function
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void set(gameobject_t *runner)
{
    runner->rect.top = 0;
    runner->rect.left = 0;
    runner->rect.width = 43;
    runner->rect.height = 68;
    runner->speed = 0;

    runner->Texture = sfTexture_createFromFile("assets/png/runner.png", NULL);
    runner->sprite = sfSprite_create();
    sfSprite_setTexture(runner->sprite, runner->Texture, sfTrue);
    sfSprite_scale(runner->sprite, (sfVector2f) {2, 2});
    sfSprite_setTextureRect(runner->sprite, runner->rect);
    runner->vector.x = 90;
    runner->vector.y = 708;
    sfSprite_setPosition(runner->sprite, runner->vector);
}

void set_texture(gameobject_t *runner, window_t *mainwindow)
{
    sfRenderWindow_drawSprite(mainwindow->window, runner->sprite, NULL);
}

void move_rect(gameobject_t *runner)
{
    runner->rect.left += 47;

    sfSprite_setTextureRect(runner->sprite, runner->rect);

}

void set_time(mytime_t *runnertime, gameobject_t *runner)
{
    runnertime->time = sfClock_getElapsedTime(runnertime->clock);
    runnertime->second = runnertime->time.microseconds / 1000000.0;
    if (runnertime->second > 0.2) {
        move_rect(runner);
        sfClock_restart(runnertime->clock);
    }
    if (runnertime->second > 0.2) {
        int size = runner->rect.left;

        if (size + 43 > 221)
            runner->rect.left = 0;
        else
            runner->rect.left += 43;
    }
}