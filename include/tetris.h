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
    char left;
    char right;
    char turn;
    char drop;
    char quit;
    char pause;
} keybindings_t;

typedef struct settings {
    keybindings_t *keys;
    vector2i_t map_size;
    int hide_next;
    int debug;
} settings_t;

typedef struct gamedata {
    settings_t *settings;
    linked_list_t *tetrominos;
    int next_tetromino;
    int high_score;
    int score;
    int lines;
    int level;
    clock_t time;
} gamedata_t;

#endif /* !TETRIS_H_ */