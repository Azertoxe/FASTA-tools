/*
** EPITECH PROJECT, 2023
** heeader
** File description:
** header
*/

#include "../include/my.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int shorting_2(const void* s1, const void* s2)
{
    const char **a = (const char **)s1;
    const char **b = (const char **)s2;
    return strcmp(*a, *b);
}

char **rm_duplicate(char **tab, int i)
{
    while (tab[i]) {
        tab[i] = tab[i + 1];
        i++;
    }
    return tab;
}

char **remove_duplicates(char **tab, int count)
{
    for (int i = 1; i < count; i++) {
        if (strcmp(tab[i], tab[i - 1]) == 0) {
            tab = rm_duplicate(tab, i);
            count--;
            i--;
        }
    }
    return tab;
}

void start_option_4(fasta_t *fasta)
{
    int i = 0;
    int i2 = 0;
    fasta->size = 0;
    char **tab = malloc(sizeof(char **) * strlen(fasta->args));

    while (fasta->args[i])
        if (fasta->args[i] == '>')
            i = save_seq(fasta, i);
    fasta->tab[fasta->size] = '\0';
    for (int idx = 1; fasta->tab[idx]; idx += 2)
        for (int idx2 = 0; fasta->tab[idx][idx2 + fasta->kmer - 1]; idx2++) {
            tab[i2] = malloc(sizeof(char *) * strlen(fasta->args));
            strncpy(tab[i2++],fasta->tab[idx] + idx2, fasta->kmer);
        }
    for (i = 0;tab[i]; i++);
    qsort(tab, i, sizeof(char *), shorting_2);
    for (int idx = 0; tab[idx]; idx++)
        printf("%s\n", tab[idx]);
}
