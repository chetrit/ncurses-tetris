/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** game structure initialization header
*/

#ifndef INIT_STRUCT_H_
#define INIT_STRUCT_H_

void init_keys_default(game_t *game);
int init_nb_tetriminos(game_t *game);
int init_tetriminos(game_t *game);
int init_keys(game_t *game, int ac, char **av);

#endif /*INIT_STRUCT_H_*/