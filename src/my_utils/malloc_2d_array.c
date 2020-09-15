/*
** EPITECH PROJECT, 2019
** malloc_2d_array
** File description:
** malloc a 2d array
*/

#include <stdlib.h>

char **malloc_2d_array(int nb_rows, int nb_cols)
{
    char **str = malloc(sizeof(char *) * nb_rows);
    int i = 0;

    if (!str)
        return (NULL);
    for (; i < nb_rows; i += 1) {
        str[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (!str[i])
            return (NULL);
    }
    return (str);
}