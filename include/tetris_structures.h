/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris header
*/

#ifndef TETRIS_STRUCTURES_H_
#define TETRIS_STRUCTURES_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct tetrimino_s
{
    char **map;
    char *name;
    int cols;
    int rows;
    unsigned int color;
    bool is_error;
} tetrimino_t;

typedef struct keys_s
{
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int next;
    int level;
    int rows;
    int cols;
    bool debug;
} keys_t;

typedef struct map_s
{
    bool filled;
    int color;
} map_t;

typedef struct pos_s
{
    int x;
    int y;
} pos_t;

typedef struct score_s
{
    unsigned int high_score;
    unsigned int current_score;
    unsigned int nb_lines;
    unsigned int level;
    unsigned int timer;
    int incr_level;
} score_t;

typedef struct game_s
{
    int nb_tetriminos;
    tetrimino_t *tetriminos;
    tetrimino_t *current;
    pos_t pos;
    pos_t old_pos;
    tetrimino_t *next;
    keys_t keys;
    map_t **map;
    bool is_finished;
    int input;
    score_t score;
    clock_t c_begin;
    clock_t c_current;
} game_t;

#endif /*TETRIS_STRUCTURES_H_*/
