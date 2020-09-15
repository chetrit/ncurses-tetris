/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>

int my_strlen(char const *src);

char *my_strdup(char const *src)
{
    char *array;
    int len = my_strlen(src);
    int i = 0;

    array = malloc(sizeof(char) * (len + 1));
    for (; i < len; i += 1) {
        array[i] = src[i];
    }
    array[i] = '\0';
    return (array);
}
