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

void tester(fasta_t *fasta)
{
    for (int idx = 0; fasta->tab[idx]; idx++)
        printf("%s\n", fasta->tab[idx]);
}

int save_seq(fasta_t *fasta, int i)
{
    int idx2 = 0;

    fasta->tab[fasta->size] = malloc(sizeof(char *) * strlen(fasta->args));
    while (fasta->args[i] != '\0' && fasta->args[i] != '\n'){
        fasta->tab[fasta->size][idx2] = fasta->args[i];
        idx2++;
        i++;
    }
    fasta->tab[fasta->size][idx2] = '\0';
    fasta->size++;
    idx2 = 0;
    fasta->tab[fasta->size] = malloc(sizeof(char *) * strlen(fasta->args));
    for (;fasta->args[i] && fasta->args[i] != '>'; i++)
        if (is_out_letter(fasta->args[i]) == 1)
            fasta->tab[fasta->size][idx2++] = fasta->args[i];
    for (idx2 = 0; fasta->tab[fasta->size][idx2]; idx2++)
        if (is_letter(fasta->tab[fasta->size][idx2]) == 1)
            fasta->tab[fasta->size][idx2] = fasta->tab[fasta->size][idx2] - 32;
    fasta->size++;
    return i;
}

void start_option_1(fasta_t *fasta)
{
    int i = 0;
    fasta->size = 0;

    while (fasta->args[i]) {
        if (fasta->args[i] == '>')
            i = save_seq(fasta, i);
    }
    tester(fasta);
}
