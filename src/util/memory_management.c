/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** memory_management
*/

#include <stdlib.h>
#include "tetris.h"

void free_tetrimino(void *t)
{
    tetrimino_t *tetrimino = t;

    free(tetrimino->name);
    for (int i = 0; tetrimino->pattern[i]; i++)
        free(tetrimino->pattern[i]);
    free(tetrimino);
}

void free_keys(keybindings_t *keys)
{
    free(keys->drop);
    free(keys->left);
    free(keys->pause);
    free(keys->quit);
    free(keys->right);
    free(keys->turn);
    free(keys);
}

void free_all(gamedata_t *data)
{
    free_keys(data->settings->keys);
    free(data->settings);
    ll_free(data->tetriminos, free_tetrimino);
    free(data);
}