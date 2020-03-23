/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** parse tetriminos
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "tetris.h"

void free_arrs(char **lines, char **split)
{
    free(lines[0]);
    free(lines);
    free(split[0]);
    free(split);
}

tetrimino_t *set_errored_tetrimino(tetrimino_t *tetrimino)
{
    tetrimino->pattern = 0;
    return tetrimino;
}

char **parse_pattern(vector2i_t size, char **lines)
{
    char **pattern = malloc(sizeof(char *) * (size.y + 1));

    for (int i = 0; i < size.y; i++) {
        if (my_strlen(lines[i + 1]) >= size.x)
            lines[i + 1][size.x] = 0;
        pattern[i] = my_strdup(lines[i + 1]);
    }
    return pattern;
}

tetrimino_t *parse_tetrimino(char *name, char *content)
{
    char **lines;
    char **split;
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));

    tetrimino->name = my_strdup(name);
    lines = my_strsplit(content, '\n');
    if (my_arrlen(lines) < 3) return set_errored_tetrimino(tetrimino);
    split = my_strsplit(lines[0], ' ');
    if (my_arrlen(split) < 3 || !my_str_isnum(split[0]) ||
        !my_str_isnum(split[1]) || !my_str_isnum(split[2]))
        return set_errored_tetrimino(tetrimino);
    tetrimino->size = v2i(my_getnbr(split[0]), my_getnbr(split[1]));
    tetrimino->color = my_getnbr(split[2]);
    tetrimino->pattern = parse_pattern(tetrimino->size, lines);
    free_arrs(lines, split);
    return tetrimino;
}

linked_list_t *get_tetriminos(void)
{
    linked_list_t *tetriminos = 0;
    DIR *t_dir = opendir("./tetriminos");
    struct dirent *file;
    char *name = my_strdup(" ");
    char *path;
    char *content;

    if (!t_dir) return 0;
    while ((file = readdir(t_dir))) {
        if (!my_str_endswith(file->d_name, ".tetrimino")) continue;
        free(name);
        name = my_strdup(file->d_name);
        name[my_strlen(name) - 10] = 0;
        path = my_strconcat("./tetriminos/", file->d_name);
        content = my_free_assign(path, read_file(path));
        tetriminos = ll_append(tetriminos, parse_tetrimino(name, content));
        free(content);
    }
    closedir(t_dir);
    return sort_tetriminos(tetriminos);
}