/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"

int main(int argc, char **argv, char **env)
{
    gamedata_t *data;

    setup_terminal(env);
    data = create_gamedata();
    data = get_settings(argc, argv, data);
    data->settings->movement_functions = setup_input(data);
    if (data->settings->debug)
        debug_mode(data);
    start_game(data);
    free_all(data);
    return 0;
}