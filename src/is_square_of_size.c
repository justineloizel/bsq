/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-bsbsq-justine.loizel
** File description:
** is_square_of_size.c
*/

#include "my_bsq.h"

int **modify_map(int **map, int nb_rows, int nb_cols, coordonates_t coord)
{
    int j = coord.coor_line;
    int i = coord.coor_col;
    int save = map[j][i];
    int temp = i;

    for (int z = 0; z < save; z++, j--) {
        for (int y = 0; y < save; y++, temp--) {
            map[j][temp] = -9;
        }
        temp = i;
    }
    return map;
}

void loop_adding_x(int **map, indexes_t *index, char *str)
{
    if (map[index->j][index->i] == -9) {
        str[index->k] = 'x';
    }
}

char *modify_str_with_x(int **map, char *filepath, int nb_rows, int nb_cols)
{
    char *str = remove_nb(load_file_in_str(filepath));
    indexes_t index;
    index.k = 0;

    for (index.j = 0; index.j < nb_rows; index.j++, index.k++) {
        for (index.i = 0; index.i < nb_cols - 1; index.i++, index.k++) {
            loop_adding_x(map, &index, str);
        }
    }
    return str;
}

int bsq_functions(char *filepath)
{
    int **map = NULL;
    int nb_rows = get_nb_rows(filepath);
    int size = get_size(filepath);
    int nb_cols = (size / nb_rows);
    char *str = NULL;

    map = load_2d_arr_from_file(filepath, nb_rows, nb_cols);
    map = find_biggest_square(map, nb_rows, nb_cols);
    map = find_coordonates_biggest_square(map, nb_rows, nb_cols);
    str = modify_str_with_x(map, filepath, nb_rows, nb_cols);
    write(1, str, my_strlen(str));
    for (int i = 0; i < nb_rows; i++)
        free(map[i]);
    free(str);
    return 0;
}

int main(int ac, char **av)
{
    int fd = 0;

    if (ac < 2) {
        write(2, "Too few arguments\n", 18);
        return 84;
    }
    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return 84;
        close(fd);
        bsq_functions(av[1]);
    }
    if (ac > 3) {
        write(2, "Too many arguments\n", 19);
        return 84;
    }
    if (ac == 3)
        generated_bsq(ac, av);
    return 0;
}
