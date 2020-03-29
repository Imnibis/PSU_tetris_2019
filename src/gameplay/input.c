/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** input
*/

#include "tetris.h"
#include <stdlib.h>
#include <unistd.h>

void no_op(gamedata_t *data) {

}

dictionary_t *create_key_dict(gamedata_t *data)
{
    dictionary_t *keys = 0;

    keys = dict_add(keys, data->settings->keys->drop, pint(0));
    keys = dict_add(keys, data->settings->keys->left, pint(0));
    keys = dict_add(keys, data->settings->keys->pause, pint(0));
    keys = dict_add(keys, data->settings->keys->quit, pint(0));
    keys = dict_add(keys, data->settings->keys->right, pint(0));
    keys = dict_add(keys, data->settings->keys->turn, pint(0));
    return keys;
}

dictionary_t *setup_input(gamedata_t *data)
{
    dictionary_t *dict = 0;

    dict = dict_add(dict, data->settings->keys->drop, move_down);
    dict = dict_add(dict, data->settings->keys->left, move_left);
    dict = dict_add(dict, data->settings->keys->pause, no_op);
    dict = dict_add(dict, data->settings->keys->quit, no_op);
    dict = dict_add(dict, data->settings->keys->right, move_right);
    dict = dict_add(dict, data->settings->keys->turn, no_op);
    data->keys_pressed = create_key_dict(data);
    data->keys_prev = create_key_dict(data);
    return dict;
}

void key_check(gamedata_t *data, int extra_keys, char *input, char *str)
{
    int *pressed = 0;
    int c = getch();

    while (c != ERR) {
        if (c == 27) extra_keys = 2;
        str = my_char_to_str(my_strlen(input) == 1 && c == '[' ? 'O' : c);
        input = my_free_assign(str, my_free_assign(input,
            my_strconcat(input, str)));
        pressed = dict_get(data->keys_prev, input);
        if (extra_keys == 0 && pressed && !*(int *) pressed) {
            (*(int *) dict_get(data->keys_pressed, input)) = 1;
            ((void (*)(gamedata_t *))
                dict_get(data->settings->movement_functions, input))(data);
            free(input);
            input = my_strdup("");
        } else if (extra_keys == 0 && pressed && *(int *) pressed)
            (*(int *) dict_get(data->keys_pressed, input)) = 1;
        c = getch();
        extra_keys -= extra_keys ? 1 : 0;
    }
}

void check_input(gamedata_t *data)
{
    char *input = my_strdup("");
    int extra_keys = 0;
    char *str;

    move(0, 0);
    dict_free(data->keys_prev, 0, free);
    data->keys_prev = data->keys_pressed;
    data->keys_pressed = create_key_dict(data);
    key_check(data, extra_keys, input, str);
}