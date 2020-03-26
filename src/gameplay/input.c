/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** input
*/

#include "tetris.h"
#include <stdlib.h>
#include <unistd.h>

void check_input(gamedata_t *data)
{
    char *input = my_strdup("");
    int c = getch();
    char *str;

    while (c != ERR) {
        str = my_char_to_str(my_strlen(input) == 2 && c == '[' ? 'O' : c);
        input = my_free_assign(str, my_free_assign(input,
            my_strconcat(input, c == 27 ? "^E" : str)));
        c = getch();
    }
    mvwprintw(data->windows->std, 0, 0, input);
    free(input);
}