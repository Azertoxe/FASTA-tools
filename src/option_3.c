/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../include/my.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    char temp;
    int end = strlen(str) - 1;

    for (int i = 0; i < end; i++) {
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
    end--;
    }
    return (str);
}

char replace_a_and_t_g_and_c(char c)
{
    if (c == 'T')
        return 'A';
    if (c == 'A')
        return 'T';
    if (c == 'C')
        return 'G';
    if (c == 'G')
        return 'C';
    return c;
}

void start_option_3(fasta_t *fasta)
{
    int i = 0;
    fasta->size = 0;

    while (fasta->args[i]) {
        if (fasta->args[i] == '>')
            i = save_seq(fasta, i);
    }
    fasta->tab[fasta->size] = '\0';
    for (int idx = 1; idx < fasta->size ; idx += 2)
        fasta->tab[idx] = my_revstr(fasta->tab[idx]);
    for (int idx = 1; idx < fasta->size ; idx += 2)
        for (int idx2 = 0; fasta->tab[idx][idx2]; idx2++)
            fasta->tab[idx][idx2] =
            replace_a_and_t_g_and_c(fasta->tab[idx][idx2]);
    tester(fasta);
}
