/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** sort
*/

#include "tetris.h"

linked_list_t *sort_step(linked_list_t *tetriminos)
{
    tetrimino_t *t;
    tetrimino_t *next;

    for (int i = 0; i < ll_len(tetriminos) - 1; i++) {
        t = ll_get(tetriminos, i);
        next = ll_get(tetriminos, i + 1);
        if (my_strcmp(t->name, next->name) > 0)
            tetriminos = ll_swap(tetriminos, i, i + 1);
    }
    return tetriminos;
}

linked_list_t *sort_tetriminos(linked_list_t *tetriminos)
{
    for (int i = 0; i < ll_len(tetriminos); i++)
        tetriminos = sort_step(tetriminos);
    return tetriminos;
}