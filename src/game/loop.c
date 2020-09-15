/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** loop of the game
*/

#include <time.h>
#include <ncurses.h>
#include "tetris_structures.h"
#include "loop.h"

void game_event_update(game_t *game)
{
    game->input = getch();
}

static void game_logic_update(game_t *game)
{
    if (!game->next) {
        if (check_end(game)) {
            return;
        }
        generate_next_tetrimino(game);
    }
    put_tetrimino(game, game->current);
}

void game_display_update(game_t *game)
{
    if (game->c_current - game->c_begin > 560000 - game->score.level * 50000) {
        game->pos.y += 1;
        clear();
        print_title();
        print_score(game);
        print_map(game);
        if (game->keys.next)
            print_next(game);
        refresh();
        game->c_begin = clock();
    }
}

void loop(game_t *game)
{
    while (!game->is_finished) {
        game_event_update(game);
        game_logic_update(game);
        game_display_update(game);
        game->c_current = clock();
    }
}
