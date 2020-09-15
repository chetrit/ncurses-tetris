/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** game structure initialization header
*/

#ifndef MY_UTILS_H_
#define MY_UTILS_H_

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_atoi(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_pow(int nb, int p);
char **malloc_2d_array(int nb_rows, int nb_cols);
int my_custom_str_isnum(char *str);

#endif /*MY_UTILS_H_*/
