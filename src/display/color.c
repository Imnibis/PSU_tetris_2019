/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** color
*/

#include "tetris.h"
#include <ncurses.h>

void init_pairs(void)
{
    start_color();
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_RED);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_WHITE);
}

void display_color(WINDOW *win, char c, vector2i_t pos, int color)
{
    wattron(win, COLOR_PAIR(color));
    mvwaddch(win, pos.y, pos.x, c);
    wattroff(win, COLOR_PAIR(color));
}