/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include "tetris_structures.h"
#include "init_game_struct.h"

int init_game_struct(game_t *game, int ac, char **av)
{
    init_keys_default(game);
    return (
        init_keys(game, ac, av)
        || init_nb_tetriminos(game)
        || init_tetriminos(game)
    );
}
