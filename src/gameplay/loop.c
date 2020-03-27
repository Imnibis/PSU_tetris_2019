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
        display_tetrimino(data, data->current_tetrimino);
        refresh_score(data);
        refresh_all(data);
        werase(data->windows->game);
        wborder(data->windows->game, ACS_VLINE, ACS_VLINE, ACS_HLINE,
            ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    }
}