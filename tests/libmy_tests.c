/*
** EPITECH PROJECT, 2019
** libmy_tests.c
** File description:
** criterion test for my library
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"

void redirect(void)
{
    cr_redirect_stdout();
}

void redirect_error(void)
{
    cr_redirect_stderr();
}

/*
    Functions left to make unit tests for:

    my_buffer
    my_concat_params
    my_revstr
    my_showstr
    my_str_to_word_array
    my_strcapitalize
    my_strcmp
    my_strncmp
    my_strstr
    my_strupcase
*/

Test(my_check_string_is_number, my_check_string_is_number_1)
{
    char *str = my_check_string_is_number("123");

    cr_expect_str_eq(str, "123");
}

Test(my_check_string_is_number, my_check_string_is_number_2)
{
    char *str = my_check_string_is_number("-123");

    cr_expect_str_eq(str, "-123");
}

Test(my_compute_power_rec, my_compute_power_rec_1)
{
    int pow = my_compute_power_rec(5, 5);
    cr_expect_eq(pow, 3125);
}

Test(my_compute_power_rec, my_compute_power_rec_2)
{
    int pow = my_compute_power_rec(5, 0);
    cr_expect_eq(pow, 1);
}

Test(my_compute_square_root, my_compute_square_root_1)
{
    int sq = my_compute_square_root(16);
    cr_expect_eq(sq, 4);
}

Test(my_compute_square_root, my_compute_square_root_2)
{
    int sq = my_compute_square_root(32768);
    cr_expect_eq(sq, 1);
}

Test(my_count_char, my_count_char_1)
{
    int count = my_count_char("Yo comment ca va", 'm');
    cr_expect_eq(count, 2);
}

Test(my_count_char, my_count_char_2)
{
    int count = my_count_char("Yo comment ca va", 'Y');
    cr_expect_eq(count, 1);
}

Test(my_cut_string, my_cut_string_1)
{
    char *str = my_cut_string("Wesh, gros comment ca va", 0, 3);
    cr_expect_str_eq(str, "Wesh");
}

Test(my_cut_string, my_cut_string_2)
{
    char *str = my_cut_string("Wesh, gros comment ca va", 6, 9);
    cr_expect_str_eq(str, "gros");
}

Test(my_get_index_char, my_get_index_char_1)
{
    int index = my_get_index_char("YYYYYYYY", 'Y', 3);
    cr_expect_eq(index, 2);
}

Test(my_get_nbr_operators, my_get_nbr_operators_1)
{
    int nbr = my_get_nbr_operators("--+-+123");
    cr_expect_eq(nbr, 5);
}

Test(my_get_sign, my_get_sign_1)
{
    char sign = my_get_sign("-123");
    cr_expect_eq(sign, '-');
}

Test(my_get_sign, my_get_sign_2)
{
    char sign = my_get_sign("+123");
    cr_expect_eq(sign, '+');
}

Test(my_get_sign, my_get_sign_3)
{
    char sign = my_get_sign("123");
    cr_expect_eq(sign, '+');
}

Test(my_getnbr, my_getnbr_1)
{
    int nbr = my_getnbr("123");
    cr_expect_eq(nbr, 123);
}

Test(my_getnbr, my_getnbr_2)
{
    int nbr = my_getnbr("--123");
    cr_expect_eq(nbr, 123);
}

Test(my_getnbr, my_getnbr_3)
{
    int nbr = my_getnbr("-123");
    cr_expect_eq(nbr, -123);
}

Test(my_int_to_str, my_int_to_str_1)
{
    char *str = my_int_to_str(123456);
    cr_expect_str_eq(str, "123456");
}

Test(my_int_to_str, my_int_to_str_2)
{
    char *str = my_int_to_str(-123456);
    cr_expect_str_eq(str, "-123456");
}

Test(my_intlen, my_int_len_1)
{
    int len = my_intlen(2132);
    cr_expect_eq(len, 4);
}

Test(my_intlen, my_int_len_2)
{
    int len = my_intlen(-2132);
    cr_expect_eq(len, 4);
}

Test(my_perror, my_perror, .init=redirect_error)
{
    my_perror("cuco");
    cr_expect_stderr_eq_str("cuco");
}

Test(my_put_nbr, my_put_nbr_1, .init=redirect)
{
    my_put_nbr(123);
    cr_expect_stdout_eq_str("123");
}

Test(my_put_nbr, my_put_nbr_2, .init=redirect)
{
    my_put_nbr(-123);
    cr_expect_stdout_eq_str("-123");
}

Test(my_putchar, my_putchar, .init=redirect)
{
    my_putchar('A');
    cr_expect_stdout_eq_str("A");
}

Test(my_putfloat, my_putfloat_1, .init=redirect)
{
    my_putfloat(1.123, 3);
    cr_expect_stdout_eq_str("1.123");
}

Test(my_putfloat, my_putfloat_2, .init=redirect)
{
    my_putfloat(-1.123, 3);
    cr_expect_stdout_eq_str("-1.123");
}

Test(my_putlong, my_putlong, .init=redirect)
{
    my_putlong(123456);
    cr_expect_stdout_eq_str("123456");
}

Test(my_putstr, my_putstr, .init=redirect)
{
    my_putstr("wesh");
    cr_expect_stdout_eq_str("wesh");
}

Test(my_show_word_array, my_show_word_array, .init=redirect)
{
    char **map = malloc(sizeof(char *) * 4);
    map[0] = malloc(sizeof(char) * 8);
    map[0] = "wesh";
    map[1] = malloc(sizeof(char) * 8);
    map[1] = "coucou";
    map[2] = 0;
    my_show_word_array(map);
    cr_expect_stdout_eq_str("wesh\ncoucou\n");
    free(map);
}

Test(my_sort_int_array, my_sort_int_array, .init=redirect)
{
    int *map = malloc(sizeof(int) * 4);
    map[0] = 9;
    map[1] = 4;
    map[2] = 0;
    map[3] = 2;
    my_sort_int_array(map, 4);
    cr_expect_stdout_eq_str("0\n2\n4\n9\n");
    free(map);
}

Test(my_str_isalpha, my_str_isalpha_1)
{
    int res = my_str_isalpha("ALPHA");
    cr_expect_eq(res, 1);
}

Test(my_str_isalpha, my_str_isalpha_2)
{
    int res = my_str_isalpha("?");
    cr_expect_eq(res, 0);
}

Test(my_str_islower, my_str_islower_1)
{
    int res = my_str_islower("lower");
    cr_expect_eq(res, 1);
}

Test(my_str_islower, my_str_islower_2)
{
    int res = my_str_islower("LOWER");
    cr_expect_eq(res, 0);
}

Test(my_str_isnum, my_str_isnum_1)
{
    int res = my_str_isnum("abc");
    cr_expect_eq(res, 0);
}

Test(my_str_isnum, my_str_isnum_2)
{
    int res = my_str_isnum("123");
    cr_expect_eq(res, 1);
}

Test(my_str_isprintable, my_str_isprintable)
{
    int res = my_str_isprintable("blabla");
    cr_expect_eq(res, 1);
}

Test(my_str_isupper, my_str_isupper)
{
    int res = my_str_isupper("UPPER");
    cr_expect_eq(res, 1);
}

Test(my_str_isupper, my_str_isupper_2)
{
    int res = my_str_isupper("upper");
    cr_expect_eq(res, 0);
}

Test(my_str_to_int, my_str_to_int_1)
{
    int res = my_str_to_int("123");
    cr_expect_eq(res, 123);
}

Test(my_str_to_int, my_str_to_int_2)
{
    int res = my_str_to_int("-123");
    cr_expect_eq(res, -123);
}

/*Test(my_strcapitalize, my_strcapitalize_1)
{
    char *str = "capit";
    str = my_strcapitalize(str);
    cr_expect_str_eq(str, "CAPIT");
}*/

Test(my_strcat, my_strcat)
{
    char *wow = malloc(sizeof(char) * 10);
    my_strcat(wow, "test");
    cr_expect_str_eq(wow, "test");
    free(wow);
}

/*Test(my_strcmp, my_strcmp)
{
    char *s1 = "wow";
    char *s2 = "wow";
    int res = my_strcmp(s1, s2);
    cr_expect_eq(res, 0);
}*/

Test(my_strcpy, my_strcpy)
{
    char *dest = malloc(sizeof(char) * 9);
    char *src = "test";
    my_strcpy(dest, src);
    cr_expect_str_eq(dest, "test");
}

Test(my_strdup, my_strdup)
{
    char *test = "dup";
    char  *str = my_strdup(test);
    cr_expect_str_eq(str, test);
}

Test(my_strlen, my_strlen)
{
    char *test = "abcde";
    int len = my_strlen(test);
    cr_expect_eq(len, 5);
}

Test(my_strncat, my_strncat)
{
    char *test = malloc(sizeof(char) * 5);
    char *str = "ABCS";
    my_strncat(test, str, 1);
    cr_expect_str_eq(test, "A");
    free(test);
}

Test(my_strncpy, my_strncpy)
{
    char *test = malloc(sizeof(char) * 5);
    char *src = "YOP";
    my_strncpy(test, src, 1);
    cr_expect_str_eq(test, "Y");
    free(test);
}

/*Test(my_strupcase, my_strupcase)
{
    char *test = "upcase";
    test = my_strupcase(test);
    cr_expect_str_eq(test, "UPCASE");
}*/

Test(my_swap, my_swap)
{
    int *tab = malloc(sizeof(int) * 3);
    tab[0] = 5;
    tab[1] = 2;
    my_swap(&tab[0], &tab[1]);
    cr_expect_eq(tab[0], 2);
    cr_expect_eq(tab[1], 5);
    free(tab);
}

Test(get_next_line, gnl_1, .init=redirect)
{
    int fd = open("bonus/test", O_RDONLY);
    char *str = get_next_line(fd);
    cr_expect_str_eq(str, "LIGNE UNE");
    free(str);
    str = get_next_line(fd);
    cr_expect_str_eq(str, "LIGNE DEUX");
    free(str);
    str = get_next_line(fd);
    cr_expect_str_eq(str, "LIGNE TROIS");
    free(str);
    close(fd);
}

Test(get_next_line, gnl_2, .init=redirect)
{
    int fd = open("bonus/test_2", O_RDONLY);
    char *str = get_next_line(fd);
    cr_expect_str_eq(str, "salut");
    free(str);
    str = get_next_line(fd);
    cr_expect_str_eq(str, "mec");
    free(str);
    str = get_next_line(fd);
    cr_expect_str_eq(str, "je me demande rien.");
    free(str);
    str = get_next_line(fd);
    cr_expect_eq(str, NULL);
    free(str);
    close(fd);
}