/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** check wront tetriminos files
*/

#include "tetris_structures.h"
#include "my_utils.h"

void fill_dims_of_tetrimino_struct(tetrimino_t *tetrimino, char *buf);

struct tmp_s
{
    int i;
    int *dim;
};

int get_nb_cols(char *buf, int max)
{
    for (int nb_stars = 0, j = 0; buf[j] != '\n' && buf[j] != '\0'; j++) {
        nb_stars += 1;
        if (buf[j] == '*' && nb_stars > max) {
            max = nb_stars;
        }
    }
    return (max);
}

int *get_dimensions(char *buf)
{
    int *dimensions = malloc(sizeof(int) * 2);
    int nb_rows = 0;
    int max = 0;
    int i = 0;

    for (; buf[0] != '\n'; buf++);
    buf += 1;
    for (i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n')
            nb_rows += 1;
    }
    nb_rows = buf[i - 1] != '\n' ? nb_rows + 1 : nb_rows;
    for (i = 0; i < nb_rows; i++, buf++) {
        max = get_nb_cols(buf, max);
        for (; buf[0] != '\n' && buf[0] != '\0'; buf++);
    }
    dimensions[0] = nb_rows;
    dimensions[1] = max;
    return (dimensions);
}

int check_error_extend(game_t *game, tetrimino_t *current,
                        char *buf, struct tmp_s *tmp)
{
    if (current->rows != tmp->dim[0] || current->cols != tmp->dim[1] ||
        tmp->dim[0] >= game->keys.rows || tmp->dim[1] >= game->keys.cols) {
        return (1);
    }
    for (tmp->i = tmp->i + 1; buf[tmp->i] != '\n'; tmp->i++);
    for (tmp->i = tmp->i + 1; buf[tmp->i] != '\0'; tmp->i++) {
        if (buf[tmp->i] != '*' && buf[tmp->i] != ' ' && buf[tmp->i] != '\n') {
            return (1);
        }
    }
    return (0);
}

int check_error(game_t *game, char *buf)
{
    tetrimino_t current;
    int i = 0;
    int *dim = NULL;
    char *stock_buf = buf;

    if (!buf || my_strlen(buf) < 7 || my_custom_str_isnum(buf))
        return (1);
    for (i = 0; buf[i] != ' ' && buf[i] != '\0'; i++);
    if (buf[i] == '\0' || my_custom_str_isnum(&buf[i + 1]))
        return (1);
    for (i = i + 1; buf[i] != '\0' && buf[i] != ' '; i++);
    if (buf[i] == '\0' || my_custom_str_isnum(&buf[i + 1]))
        return (1);
    dim = get_dimensions(stock_buf);
    fill_dims_of_tetrimino_struct(&current, stock_buf);
    if (check_error_extend(game, &current, buf, &(struct tmp_s) {i, dim})) {
        return (1);
    } else {
        return (0);
    }
}
