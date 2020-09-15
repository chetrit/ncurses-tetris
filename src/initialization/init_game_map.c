/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** init game map
*/

#include "tetris_structures.h"

int init_game_map(game_t *game)
{
    game->map = malloc(sizeof(map_t *) * game->keys.rows);
    if (game->map == NULL)
        return (1);
    for (int i = 0; i < game->keys.rows; i++) {
        game->map[i] = malloc(sizeof(map_t) * game->keys.cols);
        if (game->map[i] == NULL)
            return (1);
        for (int x = 0; x < game->keys.cols; x++) {
            game->map[i][x].filled = false;
            game->map[i][x].color = 0;
        }
    }
    return (0);
}
