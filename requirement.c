/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include <stdlib.h>
#include <stddef.h>

static int is_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

static int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
    (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

static char uncap(char c)
{
    char b = c;

    b = c - 32;
    return b;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;

    if (is_letter(str[i]) == 1)
        str[i] = uncap(str[i]);
    for (i = 1; str[i]; i++) {
        if (is_letter(str[i]) == 1 && is_alphanum(str[i - 1]) == 0)
            str[i] = uncap(str[i]);
        else
            str[i] = str[i];
    }
    return str;
}
