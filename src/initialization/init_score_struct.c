/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** init score struct
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "tetris_structures.h"

int init_high_score(void)
{
    int score = 0;
    int fd = open("src/.save", O_RDONLY);

    if (fd <= 0)
        return (-1);
    read(fd, &score, sizeof(int));
    return (score);
}

void init_score_struct(game_t *game)
{
    clock_t begin = clock();

    game->score.high_score = init_high_score();
    game->score.current_score = 0;
    game->score.nb_lines = 0;
    game->score.level = game->keys.level;
    game->score.timer = begin / CLOCKS_PER_SEC;
    game->score.incr_level = 0;
}
