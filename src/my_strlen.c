/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
