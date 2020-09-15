/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print tetriminos for debug mode
*/

#include "tetrimino.h"
#include "tetris_structures.h"
#include "my_utils.h"

int init_nb_tetriminos(game_t *game)
{
    DIR *dr = opendir(TETRIMINOS_PATH);
    struct dirent *de = NULL;
    int size = 0;

    if (!dr)
        exit(0);
    while ((de = readdir(dr))) {
        if (my_strlen(de->d_name) > my_strlen(TETRIMINO_EXTENT) && my_strcmp(
            &de->d_name[my_strlen(de->d_name) - my_strlen(TETRIMINO_EXTENT)],
            TETRIMINO_EXTENT) == 0) {
            size += 1;
        }
    }
    closedir(dr);
    game->nb_tetriminos = size;
    return (0);
}

char *load_file_in_mem(char const *filepath)
{
    struct stat sb;
    int size = 0;
    char *buf;
    int fd = 0;

    stat(filepath, &sb);
    size = sb.st_size;
    if (size == 0) {
        return (NULL);
    }
    buf = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    read(fd, buf, size);
    close(fd);
    buf[size] = '\0';
    return (buf);
}

char *get_path_and_name(char const *path, char *name)
{
    int len_path = my_strlen(path);
    char *str = malloc(sizeof(char) * (len_path + my_strlen(name) + 1));
    int i = 0;

    for (; i < len_path; i++)
        str[i] = path[i];
    for (i = 0; i < my_strlen(name); i++)
        str[i + len_path] = name[i];
    str[i + len_path] = '\0';
    return (str);
}

char *get_name_of_tetrimino(char *name)
{
    int stock = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '.') {
            stock = i;
        }
    }
    name[stock] = '\0';
    return (name);
}

char *remove_trailing_spaces(char *line)
{
    int stock = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '*') {
            stock = i;
        }
    }
    line[stock + 1] = '\n';
    line[stock + 2] = '\0';
    return (line);
}
