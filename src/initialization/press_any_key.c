/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** press any key to start
*/

#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "my_utils.h"

int prep_press_any_key(void)
{
    struct termios trm;

    if (ioctl(0, TCGETS, &trm) == -1)
        return (1);
    trm.c_lflag = trm.c_lflag & ~(ICANON);
    if (ioctl(0, TCSETS, &trm) == -1)
        return (1);
    return (0);
}

void press_any_key(void)
{
    char buff[1];

    buff[0] = '\0';
    if (prep_press_any_key())
        my_putstr("Error\n");
    while (!buff[0])
        read(0, buff, 1);
}
