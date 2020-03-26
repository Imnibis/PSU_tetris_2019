/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug
*/

#include "tetris.h"
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>

void print_tetrimino(tetrimino_t *tetrimino)
{
    my_printf("Tetriminos :  Name %s :  ", tetrimino->name);
    if (tetrimino->pattern == 0)
        my_printf("Error\n");
    else {
        my_printf("Size %d*%d :  Color %d :\n", tetrimino->size.x,
            tetrimino->size.y, tetrimino->color);
        for (int i = 0; tetrimino->pattern[i]; i++)
            my_printf("%s\n", tetrimino->pattern[i]);
    }
}

void print_key(char *title, char *key)
{
    my_printf("Key %s :  ", title);
    for (int i = 0; key[i]; i++) {
        if (key[i] == 27 || key[i] == ' ')
            my_printf("%s", key[i] == 27 ? "^E" : "(space)");
        else
            my_printf("%c", key[i]);
    }
    my_printf("\n");
}

void print_keys(keybindings_t *keys)
{
    print_key("Left", keys->left);
    print_key("Right", keys->right);
    print_key("Turn", keys->turn);
    print_key("Drop", keys->drop);
    print_key("Quit", keys->quit);
    print_key("Pause", keys->pause);
}

void debug_mode(gamedata_t *data)
{
    char buffer[20];
    struct termios info;

    my_printf("*** DEBUG MODE ***\n");
    print_keys(data->settings->keys);
    my_printf("Next :  %s\n", data->settings->hide_next ? "No" : "Yes");
    my_printf("Level :  %d\n", data->level);
    my_printf("Size :  %d*%d\n", data->settings->map_size.y,
        (data->settings->map_size.x - 1) / 2);
    my_printf("Tetriminos :  %d\n", ll_len(data->tetriminos));
    for (linked_list_t *i = data->tetriminos; i; i = i->next)
        print_tetrimino(i->data);
    my_printf("Press any key to start Tetris\n");
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
    read(0, buffer, 20);
}