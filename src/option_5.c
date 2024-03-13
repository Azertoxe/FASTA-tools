/*
** EPITECH PROJECT, 2023
** heeader
** File description:
** header
*/

#include "../include/my.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int save_seq_opt5(fasta_t *fasta, int i)
{
    int idx2 = 0;

    while (fasta->args[i] != '\0' && fasta->args[i++] != '\n');
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

char *option_5_parting(fasta_t *fasta, int idx1, int idx2)
{
    char *str = malloc(sizeof(char *) * 1000000);
    int idx3 = 0;

    if (strncmp(fasta->tab[idx1] + idx2, "ATG", 3) != 0)
        return "z";
    for (; fasta->tab[idx1][idx2]; idx2 += 3) {
        str[idx3] = fasta->tab[idx1][idx2];
        str[idx3 + 1] = fasta->tab[idx1][idx2 + 1];
        str[idx3 + 2] = fasta->tab[idx1][idx2 + 2];
        if (strncmp((fasta->tab[idx1] + idx2), "TAA", 3) == 0
        || strncmp((fasta->tab[idx1] + idx2), "TAG", 3) == 0
        || strncmp((fasta->tab[idx1] + idx2), "TGA", 3) == 0) {
            str[idx3] = '\0';
            return str;
        }
        idx3 += 3;
    }
    return "z";
}

void start_option_5(fasta_t *fasta)
{
    int i = 0;
    int i2 = 0;
    fasta->size = 0;
    char **tab = malloc(sizeof(char **) * strlen(fasta->args));

    while (fasta->args[i])
        if (fasta->args[i] == '>')
            i = save_seq_opt5(fasta, i);
    for (int idx = 0; fasta->tab[idx]; idx++)
        for (int idx2 = 0; fasta->tab[idx][idx2];) {
            tab[i2++] = option_5_parting(fasta, idx, idx2);
            idx2 += strlen(tab[i2 - 1]);
        }
    for (i = 0;tab[i]; i++);
    qsort(tab, i, sizeof(char *), shorting_2);
    for (i = 0;tab[i]; i++)
        if (tab[i][0] == 'z')
            tab[i++] = NULL;
    for (int idx = 0; tab[idx]; idx++)
        printf("%s\n", tab[idx]);
}
