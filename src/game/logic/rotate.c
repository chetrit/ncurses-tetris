/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** generate next tetrimino
*/

#include "tetris_structures.h"
#include "my_utils.h"

int check_new_map_pos(game_t *game, char **map, int i, int j)
{
    if (map[i][j] == '*') {
        if (game->pos.y + i >= game->keys.rows) {
            return (1);
        }
        if (game->pos.x + j >= game->keys.cols || game->pos.x + j < 0) {
            return (1);
        }
        if (game->map[game->pos.y + i][game->pos.x + j].filled == true) {
            return (1);
        }
    }
    return (0);
}

int check_new_map(game_t *game, char **map)
{
    int return_value = 0;

    for (int i = 0; i < game->current->cols; i++) {
        for (int j = 0;  j < game->current->rows; j++) {
            return_value = check_new_map_pos(game, map, i, j) == 1 ?
                return_value + 1 : return_value;
        }
    }
    if (return_value > 0) {
        return (1);
    } else {
        return (0);
    }
}

void rotate(game_t *game)
{

    int rows = game->current->rows;
    int cols = game->current->cols;
    char **new_map = malloc_2d_array(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_map[j][rows - 1 - i] = game->current->map[i][j];
        }
    }
    if (!check_new_map(game, new_map)) {
        free(game->current->map);
        game->current->map = new_map;
        game->current->rows = cols;
        game->current->cols = rows;
    }
}
