/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** init game
*/

#include <time.h>
#include "tetris_structures.h"
#include "init_game.h"

bool are_all_errors(game_t *game)
{
    for (int i = 0; i < game->nb_tetriminos; i++) {
        if (!game->tetriminos[i].is_error) {
            return (false);
        }
    }
    return (true);
}

int init_game(game_t *game, int ac, char **av)
{
    if (init_game_struct(game, ac, av))
        return (1);
    if (game->keys.debug)
        print_debug_mode(game);
    if (init_game_map(game) || init_game_window())
        return (1);
    if (game->nb_tetriminos == 0 || are_all_errors(game)) {
        game->is_finished = true;
        return (0);
    }
    game->current = &game->tetriminos[generate_first_tetrimino(game)];
    game->next = NULL;
    game->pos = (pos_t) {game->keys.cols / 2 - game->current->cols / 2
                        + (game->current->cols % 2 == 1 ? 0 : 1), 0};
    game->old_pos = (pos_t) {-1, -1};
    game->is_finished = false;
    init_score_struct(game);
    game->c_begin = clock();
    game->c_current = clock();
    return (0);
}
