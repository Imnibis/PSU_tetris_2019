/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** next
*/

#include "tetris.h"

void display_next(gamedata_t *data)
{
    if (!data->next_tetrimino) return;
    wresize(data->windows->next, data->next_tetrimino->tetrimino->size.y + 2,
        data->next_tetrimino->tetrimino->size.x + 2);
}