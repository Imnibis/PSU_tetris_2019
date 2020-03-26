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
#include <ncurses.h>

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

typedef struct tetrimino {
    char *name;
    vector2i_t size;
    char **pattern;
    int color;
} tetrimino_t;

typedef struct windows {
    WINDOW *std;
    WINDOW *game;
    WINDOW *score;
    WINDOW *next;
} windows_t;

typedef struct gamedata {
    settings_t *settings;
    linked_list_t *tetriminos;
    int next_tetrimino;
    int high_score;
    int score;
    int rows;
    int level;
    windows_t *windows;
    clock_t time;
} gamedata_t;

void usage(void);
void free_all(gamedata_t *data);
gamedata_t *create_gamedata(void);
gamedata_t *get_settings(int argc, char **argv, gamedata_t *data);
void debug_mode(gamedata_t *data);
void setup_terminal(char **env);
linked_list_t *get_tetriminos(void);
linked_list_t *sort_tetriminos(linked_list_t *tetriminos);
char **create_box(vector2i_t size);
WINDOW *create_win(vector2i_t pos, vector2i_t size);
void display_gui(WINDOW *win, char **gui, vector2i_t coords);
void start_game(gamedata_t *data);
void display_color(WINDOW *win, char c, vector2i_t pos, int color);
void init_pairs(void);
void display_t(vector2i_t pos, int color);
void display_e(vector2i_t pos, int color);
void display_r(vector2i_t pos, int color);
void display_i(vector2i_t pos, int color);
void display_s(vector2i_t pos, int color);
void init_score(gamedata_t *data);
void refresh_score(gamedata_t *data);
void refresh_all(gamedata_t *data);
void loop(gamedata_t *data);
int get_seconds(gamedata_t *data);
int get_minutes(gamedata_t *data);
void check_input(gamedata_t *data);

#endif /* !TETRIS_H_ */