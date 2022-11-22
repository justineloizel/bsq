/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-BSQ-justine.loizel
** File description:
** generating_maps.c
*/

#include "my_bsq.h"

char *generate_map(int nb_rows, char *av)
{
    int size = nb_rows;
    char *pattern = av;
    char *str = malloc(sizeof(char) * (size * size) + size + 1);
    int i = 0;

    for (int j = 0, k = 0; i < ((size * size) + size); i++, j++) {
        if (pattern[j] == '\0')
            j = 0;
        if (k == size) {
            k = 0;
            str[i] = '\n';
            j--;
            continue;
        }
        str[i] = pattern[j];
        k++;
    }
    str[i] = '\0';
    return str;
}

int **load_2d_arr_from_arg(char *str, int nb_rows, int nb_cols)
{
    int **double_array = NULL;
    indexes_t index;
    index.i = 0;
    index.j = 0;

    double_array = malloc(sizeof(int *) * nb_rows + 1);
    for (int m = 0; m < nb_rows; m++)
        double_array[m] = malloc(sizeof(int) * nb_cols + 1);
    for (index.k = 0; index.j < nb_rows; index.j++, index.k++) {
        for (; index.i < nb_cols; index.k++)
            double_array = loop_filling_array(&index, str, double_array);
        double_array[index.j][index.i] = -1;
        index.i = 0;
    }
    return double_array;
}

char *modify_gen_str_with_x(int **map, char *str, int nb_rows, int nb_cols)
{
    indexes_t index;
    index.k = 0;

    for (index.j = 0; index.j < nb_rows; index.j++, index.k++) {
        for (index.i = 0; index.i < nb_cols; index.i++, index.k++) {
            loop_adding_x(map, &index, str);
        }
    }
    return str;
}

int check_nb_arg(int ac, char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < 48 || av[1][i] > 57) {
            write(2, "A number is needed to create the map.\n", 38);
            return 1;
        }
    }
    return 0;
}

int generated_bsq(int ac, char **av)
{
    int **map = NULL;
    int nb_rows = my_getnbr(av[1]);
    int size = nb_rows * nb_rows;
    int nb_cols = nb_rows;
    char *str = NULL;

    if (check_nb_arg(ac, av))
        return 84;
    str = generate_map(nb_rows, av[2]);
    map = load_2d_arr_from_arg(str, nb_rows, nb_cols);
    map = find_biggest_square(map, nb_rows, nb_cols);
    map = find_coordonates_biggest_square(map, nb_rows, nb_cols);
    str = modify_gen_str_with_x(map, str, nb_rows, nb_cols);
    write(1, str, my_strlen(str));
    for (int i = 0; i < nb_rows; i++)
        free(map[i]);
    free(str);
    return 0;
}
