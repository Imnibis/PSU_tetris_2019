/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** score
*/

#include "tetris.h"
#include <time.h>
#include <ncurses.h>

int get_minutes(gamedata_t *data)
{
    return (time(NULL) - data->time) / 60;
}

int get_seconds(gamedata_t *data)
{
    return (time(NULL) - data->time) % 60;
}

void refresh_score(gamedata_t *data)
{
    mvwprintw(data->windows->score, 1, 22 -
        my_strlen(my_int_to_str(data->high_score)), "%d", data->high_score);
    mvwprintw(data->windows->score, 2, 22 -
        my_strlen(my_int_to_str(data->score)), "%d", data->score);
    mvwprintw(data->windows->score, 4, 22 -
        my_strlen(my_int_to_str(data->rows)), "%d", data->rows);
    mvwprintw(data->windows->score, 5, 22 -
        my_strlen(my_int_to_str(data->level)), "%d", data->level);
    mvwprintw(data->windows->score, 7, 22 -
        max(my_strlen(my_int_to_str(get_minutes(data))), 2) - 3, "%02d:%02d",
        get_minutes(data), get_seconds(data));
}

void init_score(gamedata_t *data)
{
    mvwprintw(data->windows->score, 1, 2, "High Score");
    mvwprintw(data->windows->score, 2, 2, "Score");
    mvwprintw(data->windows->score, 4, 2, "Lines");
    mvwprintw(data->windows->score, 5, 2, "Level");
    mvwprintw(data->windows->score, 7, 2, "Timer");
    refresh_score(data);
}