/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** map
*/

#include "tetris.h"

void display_map(gamedata_t *data)
{
    vector2i_t pos = {0, 0};

    while (data->map[pos.y]) {
        if (data->map[pos.y][pos.x] < 9)
            display_color(data->windows->game, '*', v2i(pos.x + 1, pos.y + 1),
                data->map[pos.y][pos.x] - 1);
        pos.x++;
        if (!data->map[pos.y][pos.x]) {
            pos.x = 0;
            pos.y++;
        }
    }
}

void create_map(gamedata_t *data)
{
    char **map = malloc(sizeof(char *) * (data->settings->map_size.y + 1));

    for (int i = 0; i < data->settings->map_size.y; i++) {
        map[i] = malloc(sizeof(char) * (data->settings->map_size.x + 1));
        for (int j = 0; j < data->settings->map_size.x; j++) {
            map[i][j] = 9;
        }
        map[i][data->settings->map_size.x] = 0;
    }
    map[data->settings->map_size.y] = 0;
    data->map = map;
}