/*
** EPITECH PROJECT, 2020
** keybind.c
** File description:
** keybind
*/

#include "tetris_structures.h"
#include "my_utils.h"

void set_key_next(game_t *game, void *key, char *bind);

void *get_keys_extend(keys_t *keys, char *str)
{
    if (my_strncmp(str, "--map-size=", 11) == 0)
        return (&keys->rows);
    if (my_strcmp(str, "-w") == 0 || my_strcmp(str, "--without-next") == 0) {
        keys->next = false;
        return (&keys->next);
    }
    if (my_strcmp(str, "-D") == 0 || my_strcmp(str, "--debug") == 0) {
        keys->debug = true;
        return (&keys->debug);
    }
    return (NULL);
}

void *get_keys(keys_t *keys, char *str)
{
    if (my_strcmp(str, "-L") == 0 || my_strncmp(str, "--level=", 9) == 0)
        return (&keys->level);
    if (my_strcmp(str, "-l") == 0 || my_strncmp(str, "--key-left=", 11) == 0)
        return (&keys->key_left);
    if (my_strcmp(str, "-r") == 0 || my_strncmp(str, "--key-right=", 12) == 0)
        return (&keys->key_right);
    if (my_strcmp(str, "-t") == 0 || my_strncmp(str, "--key-turn=", 11) == 0)
        return (&keys->key_turn);
    if (my_strcmp(str, "-d") == 0 || my_strncmp(str, "--key-drop=", 11) == 0)
        return (&keys->key_drop);
    if (my_strcmp(str, "-q") == 0 || my_strncmp(str, "--key-quit=", 11) == 0)
        return (&keys->key_quit);
    if (my_strcmp(str, "-p") == 0 || my_strncmp(str, "--key-pause=", 12) == 0)
        return (&keys->key_pause);
    return (get_keys_extend(keys, str));
}

char *get_binds(keys_t *keys, int *my_key, char **av, int *i)
{
    int j = 0;
    int x = 0;

    if (my_key == &keys->next || my_key == (int *) &keys->debug)
        return (NULL);
    if (my_strlen(av[*i]) == 2)
        return (av[++(*i)]);
    for (; av[*i][j] != '\0' && av[*i][j] != '=' && av[*i][j] != '{'; j++);
    if (av[*i][j++] == '\0')
        return (NULL);
    if (av[*i][j] == '{')
        j++;
    for (x = j; av[*i][x] != '\0' && av[*i][x] != '}'; x++);
    av[*i][x] = '\0';
    if (x == j)
        return (NULL);
    return (&av[*i][j]);
}

int set_key_size(game_t *game, char *bind)
{
    game->keys.rows = my_atoi(bind);
    for (; *bind >= '0' && *bind <= '9'; bind++);
    if (*bind != ',') {
        return (1);
    }
    bind++;
    game->keys.cols = my_atoi(bind);
    for (; *bind >= '0' && *bind <= '9'; bind++);
    if (*bind != '\0') {
        return (1);
    }
    return (0);
}

int set_key(game_t *game, void *key, char *bind)
{
    if (key == &game->keys.next || key == &game->keys.debug)
        return (0);
    if (key == NULL || bind == NULL)
        return (1);
    if (key == &game->keys.rows)
        return (set_key_size(game, bind));
    if (key == &game->keys.level) {
        game->keys.level = my_atoi(bind);
        return (0);
    }
    set_key_next(game, key, bind);
    return (0);
}
