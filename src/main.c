/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include "tetris.h"
#include <ncurses.h>

int main(int argc, char **argv, char **env)
{
    gamedata_t *data;

    setup_terminal(env);
    data = create_gamedata();
    data = get_settings(argc, argv, data);
    if (data->settings->debug)
        debug_mode(data);
    return 0;
}