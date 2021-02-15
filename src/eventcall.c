/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_event
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void manage_keyboard_press(sfKeyCode key, int *count, gameobject_t *debutmenu)
{
    window_t mainwindow;
    gameobject_t space;
    gameobject_t echap;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        *count = 1;
}