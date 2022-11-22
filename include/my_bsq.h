/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-BSQ-justine.loizel
** File description:
** my_bsq.h
*/

#ifndef _MY_BSQ_H_
    #define _MY_BSQ_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>

typedef struct coordonates {
    int coor_line;
    int coor_col;
    int nb_rows;
    int nb_cols;
    int save;
} coordonates_t;

typedef struct indexes {
    int i;
    int j;
    int k;
} indexes_t;

int open_file(char const *filepath);
void my_read(int fd, char *buffer, int size);
char *load_file_in_str(char const *filepath);
int my_strlen(char const *str);
char *remove_nb(char *str);
int **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int my_getnbr(char const *str);
int get_size(char *filepath);
int get_nb_rows(char *filepath);
void square_conditions(int **map, int i, int j);
int **find_biggest_square(int **map, int nb_rows, int nb_cols);
int **modify_map(int **map, int nb_rows, int nb_cols, coordonates_t coord);
char *modify_str_with_x(int **map, char *filepath, int nb_rows, int nb_cols);
int **find_coordonates_biggest_square(int **map, int nb_rows, int nb_cols);
void square_conditions_others(int **map, int i, int j, int check);
int bsq_functions(char *filepath);
int check_if_nb(char *str);
char *generate_map(int size, char *av);
int **loop_filling_array(indexes_t *index, char *str, int **double_array);
int **load_2d_arr_from_arg(char *str, int nb_rows, int nb_cols);
char *modify_gen_str_with_x(int **map, char *str, int nb_rows, int nb_cols);
void loop_adding_x(int **map, indexes_t *index, char *str);
int check_nb_arg(int ac, char **av);
int generated_bsq(int ac, char **av);
int check_content(char *str);

#endif
