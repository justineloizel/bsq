/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-BSQ-justine.loizel
** File description:
** find_info.c
*/

#include "my_bsq.h"

int get_size(char *filepath)
{
    struct stat structure;
    int size = 0;
    int fd = 0;

    stat(filepath, &structure);
    fd = open_file(filepath);
    size = structure.st_size;
    close(fd);
    return size;
}

int get_nb_rows(char *filepath)
{
    char *map_str = load_file_in_str(filepath);
    char *str = NULL;
    int nb_rows = 0;
    int size = get_size(filepath);
    int j = 0;

    str = malloc(sizeof(char) * size + 1);
    for (int i = 0; map_str[i] != '\n'; i++) {
        if (map_str[i] >= '0' && map_str[i] <= '9') {
            str[j] = map_str[i];
        } else
            return -1;
    }
    nb_rows = my_getnbr(map_str);
    free(str);
    free(map_str);
    return nb_rows;
}

static coordonates_t save_coordinates(int **map, int j, coordonates_t coord)
{
    for (int i = 0; i < coord.nb_cols; i++) {
        if (map[j][i] > coord.save) {
            coord.save = map[j][i];
            coord.coor_line = j;
            coord.coor_col = i;
        }
    }
    return coord;
}

int **find_coordonates_biggest_square(int **map, int nb_rows, int nb_cols)
{
    coordonates_t coord;
    coord.nb_rows = nb_rows;
    coord.nb_cols = nb_cols;
    coord.save = 0;

    for (int j = 0; j < nb_rows; j++)
        coord = save_coordinates(map, j, coord);
    if (coord.save == 0)
        return map;
    map = modify_map(map, nb_rows, nb_cols, coord);
    return map;
}

int **find_biggest_square(int **map, int nb_rows, int nb_cols)
{
    int j = 0;
    int i = 0;

    for (j = 0; j < nb_rows; j++) {
        for (i = 0; i < nb_cols; i++)
            square_conditions(map, i, j);
    }
    return map;
}
