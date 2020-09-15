/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** loop header
*/

#ifndef LOOP_H_
#define LOOP_H_

#include "tetris_structures.h"

//EVENT
void game_event_update(game_t *game);
void pause_loop(game_t *game);

//PRINT
void print_map(game_t *game);
void print_score(game_t *game);
void print_title(void);
void print_next(game_t *game);

//LOGIC
void put_tetrimino(game_t *game, tetrimino_t *tetrimino);
void generate_next_tetrimino(game_t *game);
int check_end(game_t *game);
void update_pos(game_t *game);

#endif /*LOOP_H*/
