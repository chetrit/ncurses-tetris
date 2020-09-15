/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print map
*/

#include <ncurses.h>
#include "tetris_structures.h"

void print_outline_map(game_t *game)
{
    attron(COLOR_PAIR(5));
    mvprintw(1, 60, "+");
    mvprintw(1, 60 + game->keys.cols * 2, "+");
    for (int i = 1; i < game->keys.cols * 2; i++) {
        mvprintw(1, 60 + i, "-");
    }
    for (int i = 0; i < game->keys.rows; i++) {
        mvprintw(2 + i, 60, "|");
        mvprintw(2 + i, 60 + game->keys.cols * 2, "|");
    }
    mvprintw(2 + game->keys.rows, 60, "+");
    mvprintw(2 + game->keys.rows, 60 + game->keys.cols * 2, "+");
    for (int i = 1; i < game->keys.cols * 2; i++) {
        mvprintw(2 + game->keys.rows, 60 + i, "-");
    }
}

void print_map(game_t *game)
{
    for (int i = 0; i < game->keys.rows; i++) {
        for (int j = 0; j < game->keys.cols; j++) {
            attron(COLOR_PAIR(game->map[i][j].color));
            mvprintw(2 + i, 61 + j * 2,
                "%c", game->map[i][j].filled == true ? '*' : ' ');
        }
    }
    print_outline_map(game);
}
