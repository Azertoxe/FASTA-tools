/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    fasta_t fasta;

    fasta.args = malloc(sizeof(char *) * 65535);
    param_handling(ac, av, &fasta);
    handler_getline(fasta.args, 65535);
    parting_start(&fasta);
}
