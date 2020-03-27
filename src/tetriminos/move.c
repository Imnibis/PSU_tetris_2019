/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move
*/

#include "tetris.h"

void move_down(gamedata_t *data) {
    data->current_tetrimino->pos.y++;
}

void move_up(gamedata_t *data) {
    data->current_tetrimino->pos.y--;
}

void move_left(gamedata_t *data) {
    data->current_tetrimino->pos.x--;
}

void move_right(gamedata_t *data) {
    data->current_tetrimino->pos.x++;
}