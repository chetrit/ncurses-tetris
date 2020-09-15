/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetrimino utils header
*/

#ifndef TETRIMINO_UTILS_H_
#define TETRIMINO_UTILS_H_

char *get_name_of_tetrimino(char *name);
char *get_path_and_name(char const *path, char *name);
char *load_file_in_mem(char const *filepath);
char *remove_trailing_spaces(char *line);
int get_nb_files(void);
int check_error(game_t *game, char *buf);
void transform_in_map(tetrimino_t *tetrimino);

#endif /*TETRIMINO_UTILS_H_*/