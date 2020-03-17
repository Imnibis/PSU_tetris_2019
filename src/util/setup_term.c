/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** setup_term
*/

#include <term.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tools.h"

char *get_terminal(char **env)
{
    for (int i = 0; env[i]; i++){
        if (!my_strncmp(env[i], "TERM=", 5))
            return my_strdup(env[i] + 5);
    }
    return 0;
}

void setup_terminal(char **env)
{
    char bp[1024];
    char *term = get_terminal(env);

    if (tgetent(bp, term) <= 0) exit(84);
    free(term);
}