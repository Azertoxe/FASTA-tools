/*
** EPITECH PROJECT, 2023
** header
** File description:
** test criterion
*/

#include <criterion/criterion.h>
char *my_strcapitalize_synthesis(char *str);
int my_strlen(char const *str);

Test(requierment, test_if_requirment_pass_pdf_test)
{
    char *test = strdup("hey, how are you? 42words forty-two; fifty+one");

    char *result = my_strcapitalize_synthesis(test);
    char *expeted = "Hey, How Are You? 42words Forty-Two; Fifty+One";
    cr_assert_str_eq(result, expeted);
    cr_assert_str_eq(test, expeted);
}