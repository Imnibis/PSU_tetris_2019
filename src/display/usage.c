/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** usage
*/

#include <stdlib.h>
#include "tetris.h"

void usage(void)
{
    my_printf("Usage:  ./tetris [options]\n");
    my_printf("Options:\n");
    my_printf(" --help\t\t\tDisplay this help\n");
    my_printf(" -L --level={num}\t\tStart Tetris at level num (def: 1)\n");
    my_printf("%s %s", " -l --key-left={K}\tMove the tetrimino LEFT using",
        "the K key (def: left arrow)\n");
    my_printf("%s %s", " -r --key-right={K}\tMove the tetrimino RIGHT using",
        "the K key (def: right arrow)\n");
    my_printf("%s %s", " -t --key-turn={K}\tTURN the tetrimino clockwise 90d",
        "using the K key (def: top arrow)\n");
    my_printf("%s %s", " -d --key-drop={K}\tDROP the tetrimino using",
        "the K key (def: down arrow)\n");
    my_printf("%s %s", " -q --key-quit={K}\tQUIT the game using",
        "the K key (def: 'q' key)\n");
    my_printf("%s %s", " -p --key-pause={K}\tPAUSE/RESTART the game using",
        "the K key (def: space bar)\n");
    my_printf("%s %s", " --map-size={row,col}\tSet the number of rows and",
        "columns of the map (def: 20,10)\n");
    my_printf(" -w --without-next\tHide next tetrimino (def: false)\n");
    my_printf(" -D --debug\t\t\tDebug mode (def: false)\n");
}