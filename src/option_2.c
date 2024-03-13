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

char replace_u_t(char c)
{
    if (c == 'T')
        return 85;
    else
        return c;
    return c;
}

void start_option_2(fasta_t *fasta)
{
    int i = 0;
    fasta->size = 0;

    while (fasta->args[i]) {
        if (fasta->args[i] == '>')
            i = save_seq(fasta, i);
    }
    fasta->tab[fasta->size] = '\0';
    for (int idx = 1; idx < fasta->size ; idx += 2)
        for (int idx2 = 0; fasta->tab[idx][idx2]; idx2++)
            fasta->tab[idx][idx2] = replace_u_t(fasta->tab[idx][idx2]);
    tester(fasta);
}
