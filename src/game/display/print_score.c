/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print score
*/

#include <ncurses.h>
#include <time.h>
#include "tetris_structures.h"

void print_score(game_t *game)
{
    clock_t current;

    attron(COLOR_PAIR(5));
    mvprintw(10, 3, "/-------------------------------\\");
    for (int i = 0; i < 12; i++)
        mvprintw(11 + i, 3, "|                               |");
    mvprintw(22, 3, "\\-------------------------------/");
    mvprintw(12, 5, "High Score % 17d", game->score.high_score);
    mvprintw(13, 5, "Score % 22d", game->score.current_score);
    mvprintw(16, 5, "Lines % 22d", game->score.nb_lines);
    mvprintw(17, 5, "Level % 22d", game->score.level);
    current = clock() / CLOCKS_PER_SEC;
    mvprintw(
        20, 5, "Timer % 18d%d:%d%d", (current - game->score.timer) / 600,
        ((current - game->score.timer) / 60) % 10,
        ((current - game->score.timer) / 10) % 6,
        (current - game->score.timer) % 10);
}
