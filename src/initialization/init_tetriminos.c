/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print tetriminos for debug mode
*/

#include "tetrimino.h"
#include "tetris_structures.h"
#include "tetrimino_utils.h"
#include "my_utils.h"

void fill_dims_of_tetrimino_struct(tetrimino_t *tetrimino, char *buf)
{
    int i = 0;
    int j = 0;

    tetrimino->rows = 0;
    tetrimino->cols = 0;
    tetrimino->color = 0;
    for (j = 0; buf[j] != ' '; j++);
    for (; buf[0] != ' '; buf++, i++) {
        tetrimino->cols += (buf[0] - 48) * my_pow(10, j - 1 - i);
    }
    for (j = 0; buf[j + 1] != ' '; j++);
    for (i = 0, buf += 1; buf[0] != ' '; buf++, i++) {
        tetrimino->rows += (buf[0] - 48) * my_pow(10,  j - 1 - i);
    }
    for (j = 0; buf[j + 1] != '\n'; j++);
    for (i = 0, buf += 1; buf[0] != '\n'; buf++, i++) {
        tetrimino->color += (buf[0] - 48) * my_pow(10, j - 1 - i);
    }
}

void fill_tetrimino_struct(game_t *game, char const *path,
                            char *name, tetrimino_t *tetrimino)
{
    char *buf = load_file_in_mem(get_path_and_name(path, name));
    FILE *file = fopen(get_path_and_name(path, name), "r");
    size_t null_size = 0;

    tetrimino->name = get_name_of_tetrimino(name);
    if (check_error(game, buf)) {
        tetrimino->is_error = true;
        return;
    } else {
        tetrimino->is_error = false;
    }
    fill_dims_of_tetrimino_struct(tetrimino, buf);
    tetrimino->map = malloc(sizeof(char *) * tetrimino->rows);
    tetrimino->map[0] = NULL;
    getline(&buf, &null_size, file);
    for (int i = 0; i < tetrimino->rows; i++) {
        tetrimino->map[i] = NULL;
        getline(&tetrimino->map[i], &null_size, file);
        tetrimino->map[i] = remove_trailing_spaces(tetrimino->map[i]);
    }
}

void swap_elems(char **arr, int x, int y)
{
    char *stock = arr[x];

    if (my_strcmp(arr[x], arr[y]) > 0) {
        arr[x] = arr[y];
        arr[y] = stock;
    }
}

char **bubble_sort_names(char **arr, game_t *game)
{
    for (int j = 0; j < game->nb_tetriminos; j++)
        for (int i = 0; i < game->nb_tetriminos - 1; i++)
            swap_elems(arr, i, i + 1);
    return (arr);
}

int init_tetriminos(game_t *game)
{
    struct dirent *de = NULL;
    DIR *dr = opendir(TETRIMINOS_PATH);
    char **names = malloc(sizeof(char *) * game->nb_tetriminos);

    game->tetriminos = malloc(sizeof(tetrimino_t) * game->nb_tetriminos);
    for (int i = 0; (de = readdir(dr));) {
        if (my_strlen(de->d_name) > my_strlen(TETRIMINO_EXTENT) && my_strcmp(
            &de->d_name[my_strlen(de->d_name) - my_strlen(TETRIMINO_EXTENT)],
            TETRIMINO_EXTENT) == 0) {
            names[i] = de->d_name;
            i += 1;
        }
    }
    names = bubble_sort_names(names, game);
    for (int i = 0; i < game->nb_tetriminos; i++) {
        fill_tetrimino_struct(game, TETRIMINOS_PATH,
                            names[i], &game->tetriminos[i]);
        transform_in_map(&game->tetriminos[i]);
    }
    return (0);
}