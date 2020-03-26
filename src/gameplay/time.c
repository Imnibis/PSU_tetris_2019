/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** time
*/

#include "tetris.h"

int get_seconds(gamedata_t *data)
{
    return ((clock() - data->time) / CLOCKS_PER_SEC) % 60;
}

int get_minutes(gamedata_t *data)
{
    return ((clock() - data->time) / CLOCKS_PER_SEC) / 60;
}