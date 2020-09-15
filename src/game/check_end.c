/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** checking whether game is finished
*/

#include "tetris_structures.h"

int check_end(game_t *game)
{
    for (int i = 0; i < game->keys.cols; i++) {
        if (game->map[game->current->rows - 1][i].filled) {
            game->is_finished = true;
            return (1);
        }
    }
    return (0);
}
