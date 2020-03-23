/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** variable
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "tetris.h"

keybindings_t *create_keybindings(void)
{
    keybindings_t *keys = malloc(sizeof(keybindings_t));

    keys->left = my_strdup(tigetstr("kcub1"));
    keys->right = my_strdup(tigetstr("kcuf1"));
    keys->drop = my_strdup(tigetstr("kcud1"));
    keys->turn = my_strdup(tigetstr("kcuu1"));
    keys->pause = my_strdup(" ");
    keys->quit = my_strdup("q");
    return keys;
}

settings_t *create_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->debug = 0;
    settings->hide_next = 0;
    settings->keys = create_keybindings();
    settings->map_size = v2i(10, 20);
    return settings;
}

gamedata_t *create_gamedata(void)
{
    gamedata_t *data = malloc(sizeof(gamedata_t));

    data->settings = create_settings();
    data->high_score = 0;
    data->level = 1;
    data->rows = 0;
    data->next_tetrimino = 0;
    data->score = 0;
    data->time = clock();
    data->tetriminos = get_tetriminos();
    return data;
}