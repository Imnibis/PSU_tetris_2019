/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** loop
*/

#include "tetris.h"

void refresh_all(gamedata_t *data)
{
    wnoutrefresh(data->windows->game);
    wnoutrefresh(data->windows->score);
    if (!data->settings->hide_next) {
        wnoutrefresh(data->windows->next);
    }
    doupdate();
    werase(data->windows->next);
    werase(data->windows->game);
    wborder(data->windows->game, ACS_VLINE, ACS_VLINE, ACS_HLINE,
        ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
}

void loop(gamedata_t *data)
{
    while (1) {
        if ((clock() - data->last_move) >= CLOCKS_PER_SEC / data->level)
            move_down(data);
        check_line(data);
        check_input(data);
        display_map(data);
        display_preview(data);
        display_tetrimino(data, data->windows->game, data->current_tetrimino);
        display_next(data);
        refresh_score(data);
        refresh_all(data);
    }
}