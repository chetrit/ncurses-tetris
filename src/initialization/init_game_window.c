/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** init game window
*/

#include "tetris_structures.h"
#include <time.h>
#include <ncurses.h>

int init_game_window(void)
{
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(false);
    keypad(stdscr, TRUE);
    cbreak();
    nodelay(stdscr, true);
    return (0);
}
