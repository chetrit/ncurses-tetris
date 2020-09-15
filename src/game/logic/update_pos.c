/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** generate next tetrimino
*/

#include <ncurses.h>
#include "tetris_structures.h"
#include "loop.h"

void rotate(game_t *game);

int is_updatable_extend(game_t *game, int offset, int i)
{
    for (int j = 0; j < game->current->cols; j++) {
        if (game->current->map[i][j] == '*' && game->map[game->pos.y + i]
            [game->pos.x + offset + j].filled == true) {
                return (1);
        }
    }
    return (0);
}

bool is_updatable(game_t *game, int offset)
{
    for (int i = 0; i < game->current->rows; i++) {
        if (game->pos.y + i == game->keys.rows)
            return (false);
        if (is_updatable_extend(game, offset, i))
            return (false);
    }
    return (true);
}

void update_pos(game_t *game)
{
    if ((char)game->input == game->keys.key_right[0] && game->pos.x +
        game->current->cols - 1 < game->keys.cols - 1 && is_updatable(game, 1))
        game->pos.x += 1;
    if ((char)game->input == game->keys.key_left[0]
        && game->pos.x > 0 && is_updatable(game, -1))
        game->pos.x -= 1;
    if ((char)game->input == game->keys.key_turn[0]) {
        rotate(game);
    }
    if ((char)game->input == game->keys.key_drop[0]
        && game->pos.y + 1 < game->keys.cols)
        game->pos.y += 1;
    if ((char)game->input == game->keys.key_quit[0]) {
        game->is_finished = true;
    }
    if ((char)game->input == game->keys.key_pause[0]) {
        pause_loop(game);
    }
}
