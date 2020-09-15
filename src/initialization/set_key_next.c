/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** set_key_next.c
*/

#include "tetris_structures.h"

void set_key_next(game_t *game, void *key, char *bind)
{
    if (key == &game->keys.key_quit)
        game->keys.key_quit = bind;
    if (key == &game->keys.key_pause)
        game->keys.key_pause = bind;
    if (key == &game->keys.key_left)
        game->keys.key_left = bind;
    if (key == &game->keys.key_right)
        game->keys.key_right = bind;
    if (key == &game->keys.key_turn)
        game->keys.key_turn = bind;
    if (key == &game->keys.key_drop)
        game->keys.key_drop = bind;
}
