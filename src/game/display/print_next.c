/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print next tetrimino
*/

#include <curses.h>
#include "tetris_structures.h"

void print_next_tetr(game_t *game, int size[2], int place_next[2])
{
    attron(COLOR_PAIR(game->next->color));
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            mvprintw(
                place_next[0] + 1 + i, place_next[1] + 1 + j * 2,
                game->next->map[i][j] == '*' ? "*" : " ");
        }
    }
}

void print_next(game_t *game)
{
    int place_next[2] = {2, 60 + game->keys.cols * 2 + 4};
    int size[2] = {game->next->rows, game->next->cols};

    mvprintw(place_next[0], place_next[1], "/");
    mvprintw(place_next[0], place_next[1] + size[1] * 2, "\\");
    mvprintw(place_next[0] + size[0] + 1, place_next[1], "\\");
    mvprintw(place_next[0] + size[0] + 1, place_next[1] + size[1] * 2, "/");
    for (int j = 0; j <= size[0] + 1; j += size[0] + 1) {
        for (int i = 1; i < size[1] * 2; i++) {
            mvprintw(place_next[0] + j, place_next[1] + i, "-");
        }
    }
    for (int j = 0; j <= size[1] * 2; j += size[1] * 2) {
        for (int i = 1; i <= size[0]; i++) {
            mvprintw(place_next[0] + i, place_next[1] + j, "|");
        }
    }
    mvprintw(1, place_next[1] + size[1] - 2, "Next");
    print_next_tetr(game, size, place_next);
}
