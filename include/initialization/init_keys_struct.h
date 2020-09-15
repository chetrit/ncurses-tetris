/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** game structure initialization header
*/

#ifndef INIT_STRUCT_H_
#define INIT_STRUCT_H_

static const char KEY_QUIT[] = {'q', '\0'};
static const char KEY_PAUSE[] = {'p', '\0'};
static const int DEFAULT_LEVEL = 1;
static const int DEFAULT_ROWS = 20;
static const int DEFAULT_COLS = 10;
static const bool DEFAULT_DEBUG_MODE = false;

int print_help(char *exe);
int set_key(game_t *game, int *key, char *bind);
int set_key_size(game_t *game, char *bind);
char *get_binds(keys_t *keys, int *my_key, char **av, int *i);
int *get_keys(keys_t *keys, char *str);

//UTILS
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
#endif /*INIT_STRUCT_H_*/
