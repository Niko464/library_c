/*
** EPITECH PROJECT, 2020
** my_str_starts_with.c
** File description:
** This is the file that handles user's input initialisation
*/

#include "my.h"

int my_str_starts_with(char *str, char *start_with)
{
    int verification = 0;
    int len_str = my_strlen(str);
    int len_starts_with = my_strlen(start_with);

    if (len_starts_with > len_str)
        return (0);
    for (int i = 0; i < my_strlen(start_with); i++) {
        if (start_with[i] == str[i])
            verification++;
    }
    if (verification == len_starts_with)
        return (1);
    return (0);
}