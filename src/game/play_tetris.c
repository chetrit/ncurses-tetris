/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** init struct
*/

#include "tetris_structures.h"
#include "play_tetris.h"

int play_tetris(int ac, char **av)
{
    game_t game;

    if (init_game(&game, ac, av))
        return (1);
    loop(&game);
    if (end(&game))
        return (1);
    return (0);
}
