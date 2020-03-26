/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** windows
*/

#include "tetris.h"
#include <ncurses.h>

WINDOW *create_win(vector2i_t pos, vector2i_t size)
{
    WINDOW *win = newwin(size.y + 2, size.x + 2, pos.y, pos.x);

    wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
        ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    return win;
}