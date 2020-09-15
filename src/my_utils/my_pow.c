/*
** EPITECH PROJECT, 2019
** my_pow
** File description:
** equivalent of pow fonction
*/

int my_pow(int nb, int p)
{
    int stock = nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0)
        return (1);
    if (p > 0) {
        stock = nb * my_pow(stock, p - 1);
    }
    return (stock);
}
