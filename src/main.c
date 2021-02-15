/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void set_window(window_t *mainwindow)
{
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;

    mainwindow->window = sfRenderWindow_create(video_mode, "Window",
    sfDefaultStyle, NULL);
}

int init_parallax(window_t *mainwindow)
{
    mainwindow->tab = malloc(sizeof(gameobject_t) * 8);

    mainwindow->tab[0] = set_parallax("assets/png/background2.png", 0, 1);
    mainwindow->tab[1] = set_parallax("assets/png/background2.png", 1920, 1);
    mainwindow->tab[2] = set_parallax("assets/png/background3.png", 0, 2);
    mainwindow->tab[3] = set_parallax("assets/png/background3.png", 1920, 2);
    mainwindow->tab[4] = set_parallax("assets/png/background1.png", 0, 3);
    mainwindow->tab[5] = set_parallax("assets/png/background1.png", 1920, 3);
    mainwindow->tab[6] = set_parallax("assets/png/background.png", 0, 4);
    mainwindow->tab[7] = set_parallax("assets/png/background.png", 1920, 4);

    return (0);
}

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_runner maps/easymap || intermediatemap || hardmap\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("    easymap level 1\n");
    my_putstr("    intermediatemap level 2\n");
    my_putstr("    hardmap level 3\n");
}

int main(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0) {
        usage();
        return (0);
    }
    gameobject_t *runner = malloc(sizeof(gameobject_t));
    gameobject_t **obstacle = NULL;
    gameobject_t debutmenu;
    window_t *mainwindow = malloc(sizeof(window_t));
    mytime_t runnertime;
    sound_base_t *sound = malloc(sizeof(sound_base_t));
    sound_base_t *collide_sound = malloc(sizeof(sound_base_t));
    sfEvent event;
    int pts = 0;
    runnertime.clock = sfClock_create();
    runner->gravity = 0;
    game_sound(sound);
    char *str = open_map(argc, argv);
    obstacle = malloc(sizeof(gameobject_t *) * my_strlen(str));
    set_window(mainwindow);
    start(&debutmenu, mainwindow);
    init_parallax(mainwindow);
    set(runner);
    obstacle = init_obstacle(obstacle, my_strlen(str));
    sfWindow_setFramerateLimit(mainwindow, 60);
    while (sfRenderWindow_isOpen(mainwindow->window)) {
        sfRenderWindow_clear(mainwindow->window, sfBlack);
        set_time(&runnertime, runner);
        while (sfRenderWindow_pollEvent(mainwindow->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(mainwindow->window);
            collide(runner, obstacle, str);
            if (event.type == sfEvtKeyPressed) {
                if (sfKeyboard_isKeyPressed(sfKeySpace)) {
                    gestion_event(runner);
                    jump_sound(sound);
                    pts += 1;
                    my_getstr(pts); } } }
        move_parallax(mainwindow);
        update(runner, sfClock_getElapsedTime(runnertime.clock));
        set_texture(runner, mainwindow);
        pop_rock(str, obstacle, mainwindow);
        sfRenderWindow_display(mainwindow->window); }
    return (0);}