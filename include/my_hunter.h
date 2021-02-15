/*
** EPITECH PROJECT, 2020
** main
** File description:
** main for graphic
*/

#ifndef MY_HUNTER
#define MY_HUNTER

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <stddef.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window/Keyboard.h>

typedef struct entity_s
{
    sfSprite *sprite;
    sfTexture *texture;
    char *name;
    sfVector2f position;
    sfIntRect rect;
}entity_t;

typedef struct hunter_s
{
    sfSprite *wait;
    sfTexture *texturewait;
    sfSprite *sprite;
    sfRenderWindow *window;
    entity_t skeletright;
    entity_t back;
    entity_t skeletleft;
    sfSprite *movetoright;
    sfSprite *background;
    sfIntRect rect;
    sfTexture *textureback;
    sfTexture *texturemovetoright;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
    sfClock *clock;
    sfTime time;
    float second;
    sfVector2f vector2f;
    sfSprite *menuspace;
    sfTexture *texturespace;
    sfIntRect rectwait;
    sfSprite *cursor;
    sfTexture *texturecursor;
}hunter_t;


void manage_mouse_click(sfMouseButtonEvent event, hunter_t *hunter);

void analyse_events(sfRenderWindow *window, sfEvent event, hunter_t *hunter);

void move_rect(hunter_t *hunter);

void manage_keyboard_press(sfKeyCode key, int *count, hunter_t *hunter);

int main(int argc, char **argv);

void usage(char **argv);

void set_texture(hunter_t *hunter);

void move_rect(hunter_t *hunter);

void set_time(hunter_t *hunter);

void sound(hunter_t *hunter);

void destroy(hunter_t *hunter);

#endif