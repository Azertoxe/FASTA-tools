/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../include/my.h"

int is_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int is_out_letter(char c)
{
    if (c == 'a' || c == 'A' || c == 'T' || c == 't' || c == 'G' || c == 'g' ||
    c == 'C' || c == 'c' || c == 'N' || c == 'n')
        return 1;
    return 0;
}
