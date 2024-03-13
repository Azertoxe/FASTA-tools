/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void getline_loop(int *c)
{
    do {
        c = getchar();
    } while (c != EOF);
}

char *handler_getline(char *str, long size)
{
    int c = 0;
    long i = 0;

    if (size == 0) {
        getline_loop(&c);
        return NULL;
    }
    for (i = 0; i < (size - 1); i = i + 1) {
        c = getchar();
        if ((c == EOF)) {
            str[i] = 0;
            return str;
        }
        str[i] = (char)(c);
    }
    str[i] = 0;
    getline_loop(&c);
    return str;
}
