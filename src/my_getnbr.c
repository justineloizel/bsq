/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int neg = 1;
    int loop = 1;

    for (;str[i] < '0' || str[i] > '9'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (;str[i] != '\n'; i++) {
        while (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - 48;
            i++;
            loop = 0;
        }
        if (loop == 0)
            return (nbr * neg);
    }
    return (nbr * neg);
}
