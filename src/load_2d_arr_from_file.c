/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-bsbsq-justine.loizel
** File description:
** load_2d_arr_from_file.c
*/

#include "my_bsq.h"

char *remove_nb(char *str)
{
    char *str_no_nb = NULL;
    int i = 0;
    int j = 0;

    for (; str[i] != '\n'; i++);
    i++;
    str_no_nb = malloc(sizeof(char) * my_strlen(str));
    for (; str[i] != '\0'; i++, j++)
        str_no_nb[j] = str[i];
    str_no_nb[j] = '\0';
    return str_no_nb;
}

int **loop_filling_array(indexes_t *index, char *str, int **double_array)
{
    if (str[index->k] != '\n') {
        if (str[index->k] == 'o')
            double_array[index->j][index->i] = 0;
        if (str[index->k] == '.')
            double_array[index->j][index->i] = 1;
        index->i++;
    }
    return double_array;
}

int **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int **double_array = NULL;
    char *str = NULL;
    indexes_t index;
    index.i = 0;
    index.j = 0;

    str = remove_nb(load_file_in_str(filepath));
    double_array = malloc(sizeof(int *) * nb_rows + 1);
    for (int m = 0; m < nb_rows; m++)
        double_array[m] = malloc(sizeof(int) * nb_cols + 1);
    for (index.k = 0; index.j < nb_rows; index.j++, index.k++) {
        for (; index.i < nb_cols - 1; index.k++)
            double_array = loop_filling_array(&index, str, double_array);
        double_array[index.j][index.i] = -1;
        index.i = 0;
    }
    return double_array;
}
