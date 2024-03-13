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

void parting_start(fasta_t *fasta)
{
    fasta->tab = malloc(sizeof(char **) * 100000);

    if (fasta->param == 1)
        start_option_1(fasta);
    if (fasta->param == 2)
        start_option_2(fasta);
    if (fasta->param == 3)
        start_option_3(fasta);
    if (fasta->param == 4)
        start_option_4(fasta);
    if (fasta->param == 5)
        start_option_5(fasta);
}
