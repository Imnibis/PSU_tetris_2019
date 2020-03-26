/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** loop
*/

#include "tetris.h"

void refresh_all(gamedata_t *data)
{
    wrefresh(data->windows->game);
    wrefresh(data->windows->score);
    if (!data->settings->hide_next)
        wrefresh(data->windows->next);
}

void loop(gamedata_t *data)
{
    while (1) {
        check_input(data);
        refresh_score(data);
        refresh_all(data);
    }
}