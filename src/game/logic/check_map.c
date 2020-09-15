/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** check map
*/

#include "tetris_structures.h"

void remove_line(game_t *game, int i)
{
    for (; i > 0; i--) {
        for (int j = game->keys.cols - 1; j >= 0; j--) {
            game->map[i][j].filled = game->map[i - 1][j].filled;
            game->map[i][j].color = game->map[i - 1][j].color;
        }
    }
    for (int j = game->keys.cols - 1; j >= 0; j--) {
        game->map[i][j].filled = false;
        game->map[i][j].color = 0;
    }
}

int check_map_next(game_t *game, int *i, int j)
{
    if (game->map[*i][j].filled == false) {
        return (-1);
    }
    if (j == 0) {
        remove_line(game, *i);
        (*i)++;
        game->score.nb_lines++;
        game->score.nb_lines % 3 == 0 ?
            game->score.incr_level = game->score.nb_lines : 0;
    }
    return (0);
}

void check_map(game_t *game)
{
    int stock_nb_lines = game->score.nb_lines;
    int stock_lvl = game->score.nb_lines;

    for (int i = game->keys.rows - 1; i >= 0; i--) {
        for (int j = game->keys.cols - 1; j >= 0; j--) {
            if (check_map_next(game, &i, j) == -1)
                break;
        }
    }
    if (game->score.level < 10 && stock_lvl < game->score.incr_level)
        game->score.level++;
    stock_nb_lines = game->score.nb_lines - stock_nb_lines;
    game->score.current_score += stock_nb_lines * stock_nb_lines * 100;
    game->score.current_score += rand() % 5 + 1;
}
