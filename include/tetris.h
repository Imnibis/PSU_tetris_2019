/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_
#include "linked.h"
#include "tools.h"
#include <time.h>

typedef struct keybindings {
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
} keybindings_t;

typedef struct settings {
    keybindings_t *keys;
    vector2i_t map_size;
    int hide_next;
    int debug;
} settings_t;

typedef struct gamedata {
    settings_t *settings;
    linked_list_t *tetriminos;
    int next_tetrimino;
    int high_score;
    int score;
    int rows;
    int level;
    clock_t time;
} gamedata_t;

typedef struct tetrimino {
    char *name;
    vector2i_t size;
    char **pattern;
    int color;
} tetrimino_t;

void usage(void);
void free_all(gamedata_t *data);
gamedata_t *create_gamedata(void);
gamedata_t *get_settings(int argc, char **argv, gamedata_t *data);
void debug_mode(gamedata_t *data);
void setup_terminal(char **env);

#endif /* !TETRIS_H_ */