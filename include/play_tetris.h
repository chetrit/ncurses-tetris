/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** play tetris header
*/

#ifndef PLAY_TETRIS_H_
#define PLAY_TETRIS_H_

int init_game(game_t *game, int ac, char **av);
void loop(game_t *game);
int end(game_t *game);

#endif /*PLAY_TETRIS_H_*/