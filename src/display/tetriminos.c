/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetriminos
*/

#include "tetris.h"

void display_tetrimino_line(gamedata_t *data, WINDOW *win, element_t *e, int i)
{
    for (int j = 0; e->tetrimino->pattern[i][j]; j++) {
        if (e->tetrimino->pattern[i][j] == '*' ||
            e->tetrimino->pattern[i][j] == '#')
            display_color(win, e->tetrimino->pattern[i][j],
                v2i(e->pos.x + j, e->pos.y + i), e->tetrimino->color);
    }
}

void display_tetrimino(gamedata_t *data, WINDOW *win, element_t *e)
{
    for (int i = 0; e && e->tetrimino->pattern[i]; i++) {
        display_tetrimino_line(data, win, e, i);
    }
}

element_t *clone(element_t *e)
{
    element_t *p;
    int i;

    if (!e) return 0;
    p = malloc(sizeof(element_t));
    p->pos = e->pos;
    p->tetrimino = malloc(sizeof(tetrimino_t));
    p->tetrimino->name = my_strdup("");
    p->tetrimino->pattern = malloc(sizeof(char *) *
        (my_arrlen(e->tetrimino->pattern) + 1));
    p->tetrimino->color = PREVIEW + e->tetrimino->color;
    for (i = 0; e->tetrimino->pattern[i]; i++) {
        p->tetrimino->pattern[i] = my_strdup(e->tetrimino->pattern);
        for (int j = 0; e->tetrimino->pattern[i][j]; j++)
            p->tetrimino->pattern[i][j] = e->tetrimino->pattern[i][j] == '*' ?
                '#' : ' ';
    }
    p->tetrimino->pattern[i] = 0;
    return p;
}

void display_preview(gamedata_t *data)
{
    element_t *e = data->current_tetrimino;
    element_t *p = clone(e);

    if (!e) return;
    while (check_collision(data, p))
        p->pos.y++;
    p->pos.y--;
    display_tetrimino(data, data->windows->game, p);
    free_tetrimino(p->tetrimino);
    free(p);
}