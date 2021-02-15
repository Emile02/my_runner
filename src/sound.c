/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** sound file
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void game_sound(sound_base_t *sound)
{
    sound->music = sfMusic_createFromFile("assets/gamemusic.ogg");
    sfMusic_play(sound->music);
    sfMusic_setLoop(sound->music, sfTrue);
    sfMusic_setVolume(sound->music, 4);
}

void jump_sound(sound_base_t *sound)
{
    sound->soundbuffer = sfSoundBuffer_createFromFile("assets/jump.wav");
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->soundbuffer);
    sfSound_setVolume(sound->sound, 4.0F);
    sfSound_play(sound->sound);
}

void music_destroy(sound_base_t *sound)
{
    sfMusic_destroy(sound->music);
}