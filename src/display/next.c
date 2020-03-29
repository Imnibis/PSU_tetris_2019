/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** next
*/

#include "tetris.h"

void display_next(gamedata_t *data)
{
    element_t *e;

    if (!data->next_tetrimino || data->settings->hide_next) return;
    e = malloc(sizeof(element_t));
    e->pos = v2i(1, 1);
    e->tetrimino = data->next_tetrimino->tetrimino;
    if (getmaxx(data->windows->next) < e->tetrimino->size.x + 2 ||
        getmaxy(data->windows->next) < e->tetrimino->size.y + 2)
        wresize(data->windows->next, e->tetrimino->size.y + 2,
            e->tetrimino->size.x + 2);
    wborder(data->windows->next, ACS_VLINE, ACS_VLINE, ACS_HLINE,
        ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    display_tetrimino(data, data->windows->next, e);
    free(e);
}