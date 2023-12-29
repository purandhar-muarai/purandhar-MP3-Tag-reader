#ifndef MAIN_H
#define	MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    e_success,
    e_failure,
    e_v23,
    e_v24
}status;

typedef struct flags
{
    char *title;
    char *year;
    char *album;
    char *artist;
    char *music;
    char *comment;

}flags;


void read_tag(FILE **fptr,flags *flag);
status validate_file(FILE *fptr,char *file);
void print_data(flags flag);
void edit_tag_data(FILE **fptr, char **argv);

#endif	/* MAIN_H */
