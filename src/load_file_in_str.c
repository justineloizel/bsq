/*
** EPITECH PROJECT, 2022
** B-CPE-110-REN-1-1-bsbsq-justine.loizel
** File description:
** load_file_in_mem.c
*/

#include "my_bsq.h"

int check_if_nb(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return 84;
        }
    }
    return 0;
}

int open_file(char const *filepath)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        write(2, "Cannot open file.\n", 18);
    return fd;
}

void my_read(int fd, char *buffer, int size)
{
    int nb;

    nb = read(fd, buffer, size);
    if (nb == -1)
        write(1, "read failed\n", 13);
    if (nb == 0)
        write(1, "file is empty\n", 15);
    close(fd);
}

char *load_file_in_str(char const *filepath)
{
    struct stat structure;
    int fd = 0;
    char *buffer = NULL;
    int size = 0;

    stat(filepath, &structure);
    fd = open_file(filepath);
    size = structure.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    my_read(fd, buffer, size);
    buffer[size] = '\0';
    check_if_nb(buffer);
    if (check_if_nb(buffer) == 84)
        return NULL;
    return buffer;
}
