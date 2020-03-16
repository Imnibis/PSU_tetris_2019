/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Computes square root
*/

int my_compute_square_root(int nb)
{
    int i = -1;
    int result = 0;

    do {
        i++;
        result = i*i;
    }
    while (result < nb);
    if (result == nb)
        return (i);
    else
        return (0);
}
