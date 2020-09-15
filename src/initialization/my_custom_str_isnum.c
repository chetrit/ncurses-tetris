/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** custom str isnum
*/

int my_custom_str_isnum(char *str)
{
    for (int i = 0; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (1);
        }
    }
    return (0);
}
