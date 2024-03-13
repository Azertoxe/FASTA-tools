/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void print_exit(char *str, int rtn)
{
    printf("%s", str);
    exit(rtn);
}

int param_handling(int ac, char **av, fasta_t *fasta)
{
    fasta->kmer = -1;

    if (ac <= 1)
        print_exit("missing argument.\n", 84);
    if (ac > 3)
        print_exit("too many argument.\n", 84);
    if (strncmp(av[1], "-h", 2) == 0)
        print_exit("help\n", 0);
    if (atoi(av[1]) > 0 && atoi(av[1]) <= 9) {
        fasta->param = atoi(av[1]);
        if (av[2] && fasta->param == 4 && atoi(av[2]) != 0) {
            fasta->kmer = atoi(av[2]);
        }
    } else
        print_exit("bad paramter.\n", 84);
    if (fasta->param == 4 && fasta->kmer <= 0)
        print_exit("bad paramter.\n", 84);
}
