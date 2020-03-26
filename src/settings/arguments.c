/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** arguments
*/

#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include "tetris.h"

vector2i_t set_map_size(char *optarg)
{
    char **size = my_strsplit(optarg, ',');
    vector2i_t map_size;

    map_size.x = my_getnbr(size[1]) * 2 + 1;
    map_size.y = my_getnbr(size[0]);
    return map_size;
}

char *check_keybindings(int arg, gamedata_t *data)
{
    switch (arg) {
        case 'l':
            return data->settings->keys->left = my_strdup(optarg);
        case 'r':
            return data->settings->keys->right = my_strdup(optarg);
        case 't':
            return data->settings->keys->turn = my_strdup(optarg);
        case 'd':
            return data->settings->keys->drop = my_strdup(optarg);
        case 'q':
            return data->settings->keys->quit = my_strdup(optarg);
        case 'p':
            return data->settings->keys->pause = my_strdup(optarg);
        default:
            return 0;
    }
}

void check_arg(int arg, gamedata_t *data)
{
    switch (arg) {
        case 'h':
            free_all(data);
            usage();
            exit(0);
        case 'L':
            data->level = my_getnbr(optarg);
            break;
        case 's':
            data->settings->map_size = set_map_size(optarg);
            break;
        case 'D':
            data->settings->debug = 1;
            break;
        case '?':
            free_all(data);
            exit(84);
        default:
            check_keybindings(arg, data);
    }
}

void get_arguments(int argc, char **argv, struct option args[],
    gamedata_t *data)
{
    char *optstring = "+hL:l:r:t:d:q:p:wD";
    int arg = 0;

    while (arg >= 0) {
        arg = getopt_long(argc, argv, optstring, args, NULL);
        check_arg(arg, data);
    }
}

gamedata_t *get_settings(int argc, char **argv, gamedata_t *data)
{
    struct option args[] = {
        {"help", no_argument, NULL, 'h'},
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 's'},
        {"without-next", no_argument, &data->settings->hide_next, 1},
        {"debug", no_argument, NULL, 'D'},
        {0, 0, 0, 0}
    };

    get_arguments(argc, argv, args, data);
    return data;
}