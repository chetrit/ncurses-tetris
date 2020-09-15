/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** put tetrimino utils header
*/

#ifndef PUT_TETRIMINO_UTILS_H_
#define PUT_TETRIMINO_UTILS_H_

int check_down(game_t *game, tetrimino_t *tetrimino, int i, int j);
void fill_rows(game_t *game, tetrimino_t *tetrimino, int i);
int check_end(game_t *game, tetrimino_t *tetrimino);
void check_map(game_t *game);
void update_pos(game_t *game);

#endif /*PUT_TETRIMINO_UTILS_H_*/