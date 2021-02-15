/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu
*/

#include "../include/my_runner.h"
#include "../include/my.h"

int set_start(gameobject_t **debutmenu, gameobject_t *space, gameobject_t *ech)
{
    (*debutmenu)->Texture = sfTexture_createFromFile
    ("assets/png/forest.png", NULL);
    (*debutmenu)->sprite = sfSprite_create();
    space->Texture = sfTexture_createFromFile
    ("assets/png/pressspace.png", NULL);
    space->sprite = sfSprite_create();
    ech->Texture = sfTexture_createFromFile
    ("assets/png/quitbutton.png", NULL);
    ech->sprite = sfSprite_create();
    sfSprite_setTexture(ech->sprite, ech->Texture, sfTrue);
    sfSprite_setTexture(space->sprite, space->Texture, sfTrue);
    sfSprite_setTexture((*debutmenu)->sprite, (*debutmenu)->Texture, sfTrue);
}

int draw_start(gameobject_t *debutmenu, window_t *mainwindow)
{
    sfRenderWindow_drawSprite(mainwindow->window, debutmenu->sprite, NULL);
    sfRenderWindow_display(mainwindow->window);
}

int start(gameobject_t *debutmenu, window_t *mainwindow)
{
    int count = 0;
    sfEvent event;
    gameobject_t space;
    gameobject_t echap;
    set_start(&debutmenu, &space, &echap);
    while (sfRenderWindow_isOpen(mainwindow->window)) {
        sfSprite_setPosition(space.sprite, (sfVector2f) {714.5, 330});
        sfRenderWindow_drawSprite(mainwindow->window, debutmenu->sprite, NULL);
        sfRenderWindow_drawSprite(mainwindow->window, echap.sprite, NULL);
        sfRenderWindow_drawSprite(mainwindow->window, space.sprite, NULL);
        sfRenderWindow_display(mainwindow->window);
        while (sfRenderWindow_pollEvent(mainwindow->window, &event)) {
            sfRenderWindow_clear(mainwindow->window, sfBlack);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(mainwindow->window);
            manage_keyboard_press(sfKeySpace, &count, &debutmenu);
            if (count == 1) {
                sfSprite_destroy(debutmenu->sprite);
                return (0); } } }
    sfSprite_destroy(debutmenu->sprite);
    sfTexture_destroy(debutmenu->Texture);
    sfSprite_destroy(space.sprite);
    sfTexture_destroy(space.Texture);
    return (0); }