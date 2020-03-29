/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** start
*/

#include "tetris.h"
#include <ncurses.h>
#include <stdlib.h>

int check_term_size(gamedata_t *data)
{
    return !(LINES < data->settings->map_size.y ||
        COLS < data->settings->map_size.x + 35);
}

void display_title(void)
{
    init_pairs();
    display_t(v2i(1, 3), COLOR_BLUE);
    display_e(v2i(5, 3), COLOR_RED);
    display_t(v2i(9, 3), COLOR_GREEN);
    display_r(v2i(13, 3), COLOR_YELLOW);
    display_i(v2i(17, 3), COLOR_BLUE);
    display_s(v2i(21, 3), COLOR_RED);
}

void create_windows(gamedata_t *data)
{
    data->windows->std = stdscr;
    data->windows->game = create_win(v2i(25, 2), data->settings->map_size);
    data->windows->score = create_win(v2i(1, 11), v2i(22, 7));
    data->windows->next = create_win(v2i(data->settings->map_size.x + 27, 2),
        v2i(7, 3));
}

void start_game(gamedata_t *data)
{
    if (!check_term_size(data)) {
        my_printf(SIZE_WARNING);
        return;
    }
    initscr();
    curs_set(0);
    noecho();
    srand(time(NULL));
    data->time = clock();
    data->last_move = clock();
    create_windows(data);
    create_map(data);
    display_title();
    init_score(data);
    wrefresh(data->windows->std);
    refresh_all(data);
    nodelay(stdscr, 1);
    loop(data);
    endwin();
}