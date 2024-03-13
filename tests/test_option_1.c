/*
** EPITECH PROJECT, 2023
** header
** File description:
** test criterion
*/

#include <criterion/criterion.h>
int is_letter(char c);
int is_out_letter(char c);

Test(is_letter, test_if_is_letter_return_corrcly_1)
{
    cr_expect(is_letter('Z') == 0);
    cr_expect(is_letter('z') == 1);
}

Test(is_out_letter, test_if_is_out_letter_return_corrcly_1)
{
    cr_expect(is_out_letter('A') == 1);
    cr_expect(is_out_letter('a') == 1);
    cr_expect(is_out_letter('T') == 1);
    cr_expect(is_out_letter('t') == 1);
    cr_expect(is_out_letter('G') == 1);
    cr_expect(is_out_letter('g') == 1);
    cr_expect(is_out_letter('C') == 1);
    cr_expect(is_out_letter('c') == 1);
    cr_expect(is_out_letter('N') == 1);
    cr_expect(is_out_letter('n') == 1);
}

Test(is_out_letter, test_if_is_out_letter_return_corrcly_0)
{
    cr_expect(is_out_letter('h') == 0);
    cr_expect(is_out_letter('"') == 0);
    cr_expect(is_out_letter('5') == 0);
    cr_expect(is_out_letter('9') == 0);
    cr_expect(is_out_letter('/') == 0);
    cr_expect(is_out_letter('\n') == 0);
    cr_expect(is_out_letter('Q') == 0);
    cr_expect(is_out_letter('b') == 0);
    cr_expect(is_out_letter('7') == 0);
    cr_expect(is_out_letter('0') == 0);
}


