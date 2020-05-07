/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** This is the file that contains the main function for the project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int ac, char **av)
{
    /*int fd = open("test", O_RDONLY);
    char *str = get_next_line(fd);
    while (str) {
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);*/
    my_printf("this is a %s test, i'm %d years old...\n", "fucking", 18);
    return (0);
}