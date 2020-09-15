/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** end of game
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "tetris_structures.h"
#include "my_utils.h"

void fill_map(game_t *game, tetrimino_t *tetrimino);
void game_display_update(game_t *game);
bool are_all_errors(game_t *game);

int set_high_score(game_t *game)
{
    int fd = 0;

    if (game->score.current_score <= game->score.high_score) {
        return (0);
    }
    fd = open("src/.save", O_WRONLY | O_TRUNC);
    if (fd <= 0)
        return (1);
    write(fd, &game->score.current_score, sizeof(int));
    return (0);
}

int end(game_t *game)
{
    if (game->nb_tetriminos == 0 || are_all_errors(game)) {
        endwin();
        return (0);
    }
    fill_map(game, game->current);
    game_display_update(game);
    endwin();
    set_high_score(game);
    my_putstr("It is Over! You've Scored ");
    my_put_nbr(game->score.current_score);
    my_putstr(" points !\n");
    my_putstr("Bye.\n");
    return (0);
}
