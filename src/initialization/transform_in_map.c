/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print tetriminos for debug mode
*/

#include "tetris_structures.h"
#include "my_utils.h"

void transform_in_map(tetrimino_t *tetrimino)
{
    char **map = NULL;

    if (tetrimino->is_error) {
        tetrimino->map = NULL;
        return;
    } else {
        map = malloc_2d_array(tetrimino->rows, tetrimino->cols);
    }
    for (int i = 0; i < tetrimino->rows; i++) {
        for (int j = 0; j < tetrimino->cols; j++)
            map[i][j] = tetrimino->map[i][j] == '*' ? '*' : ' ';
    }
    tetrimino->map = map;
}