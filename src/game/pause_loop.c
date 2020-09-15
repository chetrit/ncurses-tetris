/*
** EPITECH PROJECT, 2020
** pause_loop.c
** File description:
** pause loop
*/

#include <ncurses.h>
#include <time.h>
#include "loop.h"
#include "tetris_structures.h"

void pause_action(game_t *game, int status)
{
    if (!status) {
        game->score.current_score = 0;
        game->score.nb_lines = 0;
        game->score.level = 1;
        game->score.timer = clock() / CLOCKS_PER_SEC;
        game->c_begin = clock();
        game->pos = (pos_t) {game->keys.cols / 2 - game->current->cols / 2, 0};
        game->old_pos = (pos_t) {-1, -1};
        for (int i = 0; i < game->keys.rows; i++) {
            for (int j = 0; j < game->keys.cols; j++) {
                game->map[i][j].filled = false;
                game->map[i][j].color = 0;
            }
        }
    }
    if (status == 1) {
        game->is_finished = true;
    }
}

void print_pause(int line, char *str, int color)
{
    if (color == 1) {
        attron(COLOR_PAIR(4));
        mvprintw(LINES / 2 + line, COLS / 2 - 8, ">");
    }
    mvprintw(LINES / 2 + line, COLS / 2 - 6, str);
    if (color == 1) {
        attroff(COLOR_PAIR(4));
    }
}

void pause_loop(game_t *game)
{
    int status = -1;

    clear();
    while (1) {
        game_event_update(game);
        if (game->input == KEY_DOWN || game->input == KEY_UP)
            clear();
        if (game->input == KEY_UP && status > -1)
            status--;
        if (game->input == KEY_DOWN && status < 1)
            status++;
        if ((char)game->input == '\n')
            break;
        print_pause(-2, "Continue", status == -1);
        print_pause(0, "Restart", status == 0);
        print_pause(2, "Quit", status == 1);
        if (game->input == KEY_DOWN || game->input == KEY_UP)
            refresh();
    }
    pause_action(game, status);
}
