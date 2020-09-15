/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print title
*/

#include <ncurses.h>

void init_colors(void)
{
    start_color();
    init_pair(0, 0, 0);
    init_pair(1, 14, 0);
    init_pair(2, 27, 0);
    init_pair(3, 3, 0);
    init_pair(4, 11, 0);
    init_pair(5, 15, 0);
    init_pair(6, 10, 0);
    init_pair(7, 13, 0);
    init_pair(8, 9, 0);
}

void print_title_next(void)
{
    attron(COLOR_PAIR(2));
    mvprintw(1, 22, "* * *");
    mvprintw(2, 22, "*   *");
    mvprintw(3, 22, "* *");
    mvprintw(4, 22, "*   *");
    mvprintw(5, 22, "*   *");
    attron(COLOR_PAIR(4));
    mvprintw(1, 29, "*");
    mvprintw(3, 29, "*");
    mvprintw(4, 29, "*");
    mvprintw(5, 29, "*");
    attron(COLOR_PAIR(8));
    mvprintw(1, 32, "* * *");
    mvprintw(2, 32, "*");
    mvprintw(3, 32, "* * *");
    mvprintw(4, 36, "*");
    mvprintw(5, 32, "* * *");
    attroff(COLOR_PAIR(8));
}

void print_title(void)
{
    init_colors();
    attron(COLOR_PAIR(1));
    mvprintw(1, 1, "* * *");
    mvprintw(2, 3, "*");
    mvprintw(3, 3, "*");
    mvprintw(4, 3, "*");
    mvprintw(5, 3, "*");
    attron(COLOR_PAIR(6));
    mvprintw(1, 8, "* * *");
    mvprintw(2, 8, "*");
    mvprintw(3, 8, "* *");
    mvprintw(4, 8, "*");
    mvprintw(5, 8, "* * *");
    attron(COLOR_PAIR(7));
    mvprintw(1, 15, "* * *");
    mvprintw(2, 17, "*");
    mvprintw(3, 17, "*");
    mvprintw(4, 17, "*");
    mvprintw(5, 17, "*");
    print_title_next();
}
