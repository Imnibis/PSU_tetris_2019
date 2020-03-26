/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** title
*/

#include "tetris.h"
#include <ncurses.h>

void display_t(vector2i_t pos, int color)
{
    for (int i = 0; i < 3; i++)
        display_color(stdscr, '#', v2i(pos.x + i, pos.y), color);
    for (int i = 1; i <= 4; i++)
        display_color(stdscr, '#', v2i(pos.x + 1, pos.y + i), color);
}

void display_e(vector2i_t pos, int color)
{
    for (int i = 0; i < 3; i++) {
        display_color(stdscr, '#', v2i(pos.x + i, pos.y), color);
        display_color(stdscr, '#', v2i(pos.x + i, pos.y + 4), color);
        if (i != 2)
            display_color(stdscr, '#', v2i(pos.x + i, pos.y + 2), color);
    }
    for (int i = 1; i < 4; i++)
        display_color(stdscr, '#', v2i(pos.x, pos.y + i), color);
}

void display_r(vector2i_t pos, int color)
{
    for (int i = 0; i < 5; i++) {
        display_color(stdscr, '#', v2i(pos.x, pos.y + i), color);
        if (i != 2)
            display_color(stdscr, '#', v2i(pos.x + 2, pos.y + i), color);
    }
    display_color(stdscr, '#', v2i(pos.x + 1, pos.y), color);
    display_color(stdscr, '#', v2i(pos.x + 1, pos.y + 2), color);
}

void display_i(vector2i_t pos, int color)
{
    for (int i = 0; i < 3; i++) {
        display_color(stdscr, '#', v2i(pos.x + i, pos.y), color);
        display_color(stdscr, '#', v2i(pos.x + i, pos.y + 4), color);
    }
    for (int i = 1; i < 4; i++)
        display_color(stdscr, '#', v2i(pos.x + 1, pos.y + i), color);
}

void display_s(vector2i_t pos, int color)
{
    for (int i = 0; i < 3; i++) {
        display_color(stdscr, '#', v2i(pos.x + i, pos.y), color);
        display_color(stdscr, '#', v2i(pos.x + i, pos.y + 2), color);
        display_color(stdscr, '#', v2i(pos.x + i, pos.y + 4), color);
    }
    for (int i = 0; i < 3; i++) {
        display_color(stdscr, '#', v2i(pos.x, pos.y + i), color);
        display_color(stdscr, '#', v2i(pos.x + 2, pos.y + i + 2), color);
    }
}