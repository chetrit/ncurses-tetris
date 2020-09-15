/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** generate next tetrimino
*/

#include <stdlib.h>
#include "tetris_structures.h"

void generate_next_tetrimino(game_t *game)
{
    int next_tetrimino = rand() % game->nb_tetriminos;

    while (game->tetriminos[next_tetrimino].is_error == true) {
        next_tetrimino = rand() % game->nb_tetriminos;
    }
    game->next = &game->tetriminos[next_tetrimino];
}

int generate_first_tetrimino(game_t *game)
{
    int first_tetrimino = rand() % game->nb_tetriminos;

    while (game->tetriminos[first_tetrimino].is_error == true) {
        first_tetrimino = rand() % game->nb_tetriminos;
    }
    return (first_tetrimino);
}