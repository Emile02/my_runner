/*
** EPITECH PROJECT, 2020
** game object
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>

#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>


#include "sys/stat.h"
#include "sys/types.h"
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

typedef struct gameobject_s {

    sfMusic *music;
    sfSprite *sprite;
    sfTexture *Texture;
    sfIntRect rect;
    sfVector2f vector;
    float gravity;
    float x;
    float speed;
}gameobject_t;

typedef struct sound_base_s {
    sfMusic *music;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
}sound_base_t;

typedef struct window_s {
    gameobject_t **tab;
    sfRenderWindow *window;
}window_t;

typedef struct mytime_s {

    sfClock *clock;
    sfTime time;
    float second;
}mytime_t;

void manage_keyboard_press(sfKeyCode key, int *count, gameobject_t *debutmenu);

gameobject_t *set_obstacle(int i);

char *open_map(int argc, char **argv);

void set_texture(gameobject_t *runner, window_t *mainwindow);

void set(gameobject_t *runner);

gameobject_t *set_parallax(char *path_to_png, float x, float speed);

void game_object(gameobject_t *runner);

void destroy(window_t *mainwindow);

void display(gameobject_t *runner, window_t *mainwindow);

void move_rect(gameobject_t *runner);

void set_time(mytime_t *runnertime, gameobject_t *runner);

void parallax_1(gameobject_t *first_plan);

void parallax_2(gameobject_t *first_plan1);

void parallax_3(gameobject_t *first_plan2);

void display_my_parralax(gameobject_t *first_plan, gameobject_t *first_plan1, gameobject_t *first_plan2, gameobject_t *first_plan3, window_t *mainwindow);

void display_parallax(gameobject_t *first_plan2);

void move_parallax(window_t *mainwindow);

void gestion_event(gameobject_t *runner);

void gestion_hitbox(gameobject_t *runner);

void update(gameobject_t *runner, sfTime time);

void game_sound(sound_base_t *sound);

void music_destroy(sound_base_t *sound);

void jump_sound(sound_base_t *sound);

void sound_for_end(sound_base_t *end_sound);

int pop_rock(char *str, gameobject_t **obstacle, window_t *mainwindow);

int draw_start(gameobject_t *debutmenu, window_t *mainwindow);

int set_start(gameobject_t **debutmenu, gameobject_t *space, gameobject_t *echap);

void score(window_t *mainwindow);

int negative(int nb, int size);

char *str_creation(int nb, int count, int i, char *str);

char *my_getstr(int nb);

gameobject_t **init_obstacle(gameobject_t **obstacle, int nb);

void collide(gameobject_t *runner, gameobject_t *obstacle, char *str);

#endif /* !MY_RUNNER_H_ */