/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** puts a tetrimino into the 2d map
*/

#include "tetris_structures.h"
#include "put_tetrimino_utils.h"

int check_bottom(game_t *game, tetrimino_t *tetrimino)
{
    int return_value = 0;

    for (int i = 0; i < tetrimino->rows; i++) {
        for (int j = 0;  j < tetrimino->cols; j++) {
            return_value = check_down(game, tetrimino, i, j) == 1 ?
                return_value + 1 : return_value;
        }
    }
    if (return_value > 0) {
        return (1);
    } else {
        return (0);
    }
}

void remove_old_tetrimino(game_t *game, tetrimino_t *tetrimino)
{
    if (game->old_pos.x == -1 && game->old_pos.y == -1)
        return;
    for (int i = 0; i < tetrimino->rows; i++) {
        for (int j = 0; j < tetrimino->cols; j++) {
            tetrimino->map[i][j] == '*' ? game->map[game->old_pos.y + i]
                [game->old_pos.x + j].filled = false : 1;
        }
    }
}

void fill_map(game_t *game, tetrimino_t *tetrimino)
{
    for (int i = 0; i < tetrimino->rows; i++) {
        fill_rows(game, tetrimino, i);
    }
}

void put_tetrimino(game_t *game, tetrimino_t *tetrimino)
{
    remove_old_tetrimino(game, tetrimino);
    update_pos(game);
    if (check_bottom(game, tetrimino) == 1) {
        game->pos.y--;
        fill_map(game, tetrimino);
        game->current = game->next;
        game->next = NULL;
        game->pos = (pos_t) {game->keys.cols / 2 - game->current->cols / 2, 0};
        game->old_pos = (pos_t) {-1, -1};
        check_map(game);
        return;
    }
    game->old_pos = game->pos;
    fill_map(game, tetrimino);
}
