/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init game header
*/

#ifndef INIT_GAME_H_
#define INIT_GAME_H_

int init_game_struct(game_t *game, int ac, char **av);
void print_debug_mode(game_t *game);
int init_game_map(game_t *game);
int init_game_window(void);
int generate_first_tetrimino(game_t *game);
void init_score_struct(game_t *game);

#endif /*INIT_GAME_H_*/