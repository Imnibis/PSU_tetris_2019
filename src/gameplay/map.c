/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** map
*/

#include "tetris.h"

int remove_line(char **map, int line)
{
    int i;
    free(map[line]);
    for (i = line; i > 0; i--)
        map[i] = map[i - 1];
    map[0] = malloc(sizeof(char) * my_strlen(map[line]));
    for (i = 0; i < my_strlen(map[line]); i++)
        map[0][i] = 9;
    map[0][i] = 0;
    return 0;
}

void add_points(gamedata_t *data, int lines_nb)
{
    switch (lines_nb) {
        case 0:
            break;
        case 1:
            data->score += 40;
            break;
        case 2:
            data->score += 100;
            break;
        case 3:
            data->score += 300;
            break;
        default:
            data->score += 1200;
    }
}

void check_line(gamedata_t *data)
{
    vector2i_t pos = {0, 0};
    int has_gap = 0;
    int line_count = 0;

    while (data->map[pos.y]) {
        if (!has_gap && data->map[pos.y][pos.x] == 9)
            has_gap = 1;
        pos.x++;
        if (!data->map[pos.y][pos.x]) {
            pos.x = has_gap ? 0 : remove_line(data->map, pos.y);
            line_count++;
            has_gap = 0;
            pos.y++;
        }
    }
    if (line_count > data->rows % 10)
        data->level += line_count / 10 + 1;
    data->rows += line_count;
    add_points(data, line_count);
}