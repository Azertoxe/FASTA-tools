/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef MY_H
    #define MY_H

typedef struct fasta_s {
    char **tab;
    char *args;
    int size;
    int param;
    int kmer;
} fasta_t;

char *handler_getline(char *str, long size);
int param_handling(int ac, char **av, fasta_t *fasta);
void parting_start(fasta_t *fasta);
void start_option_1(fasta_t *fasta);
void start_option_2(fasta_t *fasta);
void start_option_3(fasta_t *fasta);
void start_option_4(fasta_t *fasta);
void start_option_5(fasta_t *fasta);
int shorting_2(const void *s1, const void *s2);
int save_seq(fasta_t *fasta, int i);
void tester(fasta_t *fasta);
int is_letter(char c);
int is_out_letter(char c);
int save_seq(fasta_t *fasta, int i);


#endif /* !header */
