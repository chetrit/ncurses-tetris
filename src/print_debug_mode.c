/*
** EPITECH PROJECT, 2020
** debug_mode.c
** File description:
** debug mode
*/

#include "tetris_structures.h"
#include "key_consts.h"
#include "my_utils.h"
#include <ncurses.h>

void press_any_key(void);

void print_key(char *key)
{
    if (my_strlen(key) != 1)
        my_putstr(key);
    if (key[0] == ' ')
        my_putstr("(space)");
    if (key[0] == (char)KEY_LEFT)
        my_putstr("^EOD");
    if (key[0] == (char)KEY_RIGHT)
        my_putstr("^EOC");
    if (key[0] == (char)KEY_UP)
        my_putstr("^EOA");
    if (key[0] == (char)KEY_DOWN)
        my_putstr("^EOB");
    if (*key != ' ' && *key != (char)KEY_LEFT && *key != (char)KEY_RIGHT
        && *key != (char)KEY_UP && *key != (char)KEY_DOWN
        && my_strlen(key) == 1)
        my_putstr(key);
}

void print_map_tetriminos(tetrimino_t *tetriminos)
{
    for (int i = 0; i < tetriminos->rows; i++) {
        for (int j = 0; j < tetriminos->cols; j++) {
            my_putchar(tetriminos->map[i][j]);
        }
        my_putchar('\n');
    }
}

void print_tetriminos(game_t *game)
{
    my_putstr("Tetriminos : ");
    my_put_nbr(game->nb_tetriminos);
    my_putchar('\n');
    for (int i = 0; i < game->nb_tetriminos; i++) {
        my_putstr("Tetriminos : Name ");
        my_putstr(game->tetriminos[i].name);
        if (game->tetriminos[i].is_error == true) {
            my_putstr(": Error\n");
            continue;
        }
        my_putstr(" : Size ");
        my_put_nbr(game->tetriminos[i].cols);
        my_putchar('*');
        my_put_nbr(game->tetriminos[i].rows);
        my_putstr(" : Color ");
        my_put_nbr(game->tetriminos[i].color);
        my_putstr(" :\n");
        print_map_tetriminos(&game->tetriminos[i]);
    }
}

void print_debug_mode_extend(game_t *game)
{
    my_putstr("Key Left : ");
    print_key(game->keys.key_left);
    my_putstr("\nKey Right : ");
    print_key(game->keys.key_right);
    my_putstr("\nKey Turn : ");
    print_key(game->keys.key_turn);
    my_putstr("\nKey Drop : ");
    print_key(game->keys.key_drop);
    my_putstr("\nKey Quit : ");
    print_key(game->keys.key_quit);
    my_putstr("\nKey Pause : ");
    print_key(game->keys.key_pause);
}

void print_debug_mode(game_t *game)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_debug_mode_extend(game);
    my_putstr("\nNext : ");
    if (game->keys.next == true)
        my_putstr("Yes\n");
    if (game->keys.next == false)
        my_putstr("No\n");
    my_putstr("Level : ");
    my_put_nbr(game->keys.level);
    my_putstr("\nSize : ");
    my_put_nbr(game->keys.rows);
    my_putchar('*');
    my_put_nbr(game->keys.cols);
    my_putchar('\n');
    print_tetriminos(game);
    my_putstr("Press any key to start Tetris\n");
    press_any_key();
}
