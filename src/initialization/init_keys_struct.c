/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include "tetris_structures.h"
#include "key_consts.h"
#include "init_keys_struct.h"

int check_keys_more(char **tab, int i)
{
    for (int j = i + 1; tab[j]; j++) {
        if (!my_strcmp(tab[i], tab[j])) {
            return (1);
        }
    }
    return (0);
}

int check_keys(keys_t *keys)
{
    char *tab[] = {
        keys->key_left, keys->key_right, keys->key_turn, keys->key_drop,
        keys->key_quit, keys->key_pause, NULL};

    for (int i = 0; tab[i]; i++) {
        if (check_keys_more(tab, i) == 1) {
            return (1);
        }
    }
    if (keys->level > 10 || keys->level < 1) {
        return (1);
    }
    return (0);
}

void init_keys_default(game_t *game)
{
    game->keys.key_left = my_strdup(MY_KEY_LEFT);
    game->keys.key_right = my_strdup(MY_KEY_RIGHT);
    game->keys.key_turn = my_strdup(MY_KEY_TURN);
    game->keys.key_drop = my_strdup(MY_KEY_DROP);
    game->keys.key_quit = my_strdup(KEY_QUIT);
    game->keys.key_pause = my_strdup(KEY_PAUSE);
    game->keys.next = true;
    game->keys.level = DEFAULT_LEVEL;
    game->keys.rows = DEFAULT_ROWS;
    game->keys.cols = DEFAULT_COLS;
    game->keys.debug = DEFAULT_DEBUG_MODE;
}

int init_keys(game_t *game, int ac, char **av)
{
    void *key = NULL;
    char *bind = NULL;

    for (int i = 1; i < ac; i++) {
        key = get_keys(&game->keys, av[i]);
        bind = get_binds(&game->keys, key, av, &i);
        if (set_key(game, key, bind) == 1) {
            print_help(av[0]);
            return (1);
        }
    }
    if (check_keys(&game->keys) == 1) {
        print_help(av[0]);
        return (1);
    }
    return (0);
}
