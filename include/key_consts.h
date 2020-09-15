/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** key constants header
*/

#ifndef KEY_CONSTS_H_
#define KEY_CONSTS_H_

#include <ncurses.h>

static const char MY_KEY_LEFT[2] = {(char)KEY_LEFT, '\0'};
static const char MY_KEY_RIGHT[2] = {(char)KEY_RIGHT, '\0'};
static const char MY_KEY_TURN[2] = {(char)KEY_UP, '\0'};
static const char MY_KEY_DROP[2] = {(char)KEY_DOWN, '\0'};

#endif /*KEY_CONSTS_H*/
