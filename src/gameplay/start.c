/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** start
*/

#include "tetris.h"
#include <ncurses.h>

int check_term_size(gamedata_t *data)
{
    return !(LINES < data->settings->map_size.y ||
        COLS < data->settings->map_size.x);
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
    char buff[10];

    if (!check_term_size(data)) return;
    initscr();
    curs_set(0);
    data->time = time(NULL);
    create_windows(data);
    display_title();
    init_score(data);
    wrefresh(data->windows->std);
    wrefresh(data->windows->game);
    wrefresh(data->windows->score);
    if (!data->settings->hide_next)
        wrefresh(data->windows->next);
    nodelay(stdscr, 1);
    while (1) {
        if (getch() != ERR)
            break;
        refresh_score(data);
        wrefresh(data->windows->game);
        wrefresh(data->windows->score);
        if (!data->settings->hide_next)
            wrefresh(data->windows->next);
    }
    endwin();
}