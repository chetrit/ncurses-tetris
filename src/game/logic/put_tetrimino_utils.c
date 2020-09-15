/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** puts tetrimino's utils
*/

#include "tetris_structures.h"

int check_down(game_t *game, tetrimino_t *tetrimino, int i, int j)
{
    if (game->pos.y + i == game->keys.rows)
        return (1);
    if (tetrimino->map[i][j] == '*') {
        if (game->map[game->pos.y + i][game->pos.x + j].filled == true) {
            return (1);
        }
    }
    return (0);
}

void fill_rows(game_t *game, tetrimino_t *tetrimino, int i)
{
    for (int j = 0; j < tetrimino->cols; j++) {
        if (tetrimino->map[i][j] == '*') {
            game->map[game->pos.y + i][game->pos.x + j] =
                (map_t) {true, tetrimino->color};
        }
    }
}