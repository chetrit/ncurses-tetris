/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include <stddef.h>
#include "my_utils.h"

int play_tetris(int ac, char **av);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);

static const char *USAGE = " [options]\n"
"Options:\n"
" --help\t\t\tDisplay this help\n"
" -L --level={num}\tStart Tetris at level num (def: 1)\n"
" -l --key-left={K}\tMove the tetrimino LEFT using the K key (def: left arrow)"
"\n -r --key-right={K}\tMove the tetrimino RIGHT using the K key"
" (def: right arrow)\n"
" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using the K key (def: top"
"arrow)\n"
" -d --key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n"
" -q --key-quit={K}\tQUIT the game using the K key (def: 'q' key)\n"
" -p --key-pause={K}\tPAUSE/RESTART the game using the K key (def: space bar)\n"
" --map-size={row,col}\tSet the numbers of rows and columns"
" of the map (def: 20,10)\n"
" -w --without-next\tHide next tetrimino (def: false)\n"
" -D --debug\t\tDebug mode (def: false)\n";

int print_help(char *exe)
{
    my_putstr("Usage:\t");
    my_putstr(exe);
    my_putstr(USAGE);
    return (0);
}

char *get_term(char **env)
{
    if (!env) {
        return (NULL);
    }
    for (int i = 0; env[i]; i++) {
        if (!my_strncmp(env[i], "TERM=", 5) && my_strlen(env[i]) > 6) {
            return (&env[i][5]);
        }
    }
    return (NULL);
}

int main(int ac, char **av, char **env)
{
    char *term = get_term(env);

    if (!term)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "--help") == 0) {
        return (print_help(av[0]));
    } else if (play_tetris(ac, av)) {
        return (84);
    }
    return (0);
}
