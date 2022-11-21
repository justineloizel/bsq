/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-BSQ-justine.loizel
** File description:
** check_square.c
*/

#include "my_bsq.h"

void square_conditions_others(int **map, int i, int j, int check)
{
    if (map[j - 1][i] <= map[j][i - 1] &&
        map [j - 1][i] <= map[j - 1][i - 1] &&
        map[j - 1][i] > 0 && check == 0) {
            map[j][i] = map[j - 1][i] + 1;
            check = 1;
        }
    if (map[j][i - 1] == 1 && map[j - 1][i] == 1
        && map[j - 1][i - 1] == 1 && check == 0) {
            map[j][i] = map[j][i] + 1;
            check = 1;
        }
}

void square_conditions(int **map, int i, int j)
{
    int check = 0;

    if (j != 0 && i != 0 && map[j][i] == 1) {
        if (map[j][i - 1] <= map[j - 1][i] &&
        map[j][i - 1] <= map[j - 1][i - 1] && map[j][i - 1] > 0 &&
        check == 0) {
            map[j][i] = map[j][i - 1] + 1;
            check = 1;
        }
        if (map[j - 1][i - 1] <= map[j][i - 1] &&
        map[j - 1][i - 1] <= map[j - 1][i] &&
        map[j - 1][i - 1] > 0 && check == 0) {
            map[j][i] = map[j - 1][i - 1] + 1;
            check = 1;
        }
        square_conditions_others(map, i, j, check);
    }
}
