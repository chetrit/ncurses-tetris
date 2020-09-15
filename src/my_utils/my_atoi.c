/*
** EPITECH PROJECT, 2020
** my_atoi.c
** File description:
** string to int
*/

int check_overflow(int nb, int stock, int sign)
{
    if (sign > 0 && nb < stock)
        return (-1);
    if (sign < 0 && nb > stock)
        return (-1);
    return (0);
}

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;
    int stock = nb;

    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            sign = -sign;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        if (nb >= 0)
            nb = nb * 10 + str[i] - 48;
        if (nb < 0)
            nb = nb * 10 - (str[i] - 48);
        if (sign < 0 && nb > 0)
            nb = nb * sign;
        if (check_overflow(nb, stock, sign) == -1)
            return (0);
        stock = nb;
    }
    return (nb);
}