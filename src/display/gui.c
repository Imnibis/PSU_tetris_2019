/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** gui
*/

#include "tetris.h"
#include <stdlib.h>
#include <ncurses.h>

void display_gui(WINDOW *win, char **gui, vector2i_t coords)
{
    for (int i = 0; gui[i]; i++)
        mvwprintw(win, coords.x, coords.y + i, gui[i]);
}

char **create_box(vector2i_t size)
{
    vector2i_t pos = {0, 0};
    char **box = malloc(sizeof(char *) * (size.y + 1));

    if (size.y != 0)
        box[0] = malloc(sizeof(char) * (size.x + 1));
    while (pos.y < size.y) {
        box[pos.y][pos.x] = 'a';
        pos.x++;
        if (pos.x >= size.x) {
            box[pos.y][pos.x] = 0;
            pos.x = 0;
            pos.y++;
            box[pos.y] = pos.y < size.y ? malloc(sizeof(char) * (size.x + 1))
                : 0;
        }
    }
    return box;
}