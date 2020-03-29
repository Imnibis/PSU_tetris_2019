/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** color.c
*/

#include "tetris.h"

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
    init_pair(PREVIEW + COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(PREVIEW + COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void display_color(WINDOW *win, char c, vector2i_t pos, int color)
{
    wattron(win, COLOR_PAIR(color));
    mvwaddch(win, pos.y, pos.x, c);
    wattroff(win, COLOR_PAIR(color));
}