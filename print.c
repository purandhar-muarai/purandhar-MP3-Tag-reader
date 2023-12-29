#include "main.h"


void print_data(flags flag)
{
    printf("----------------DETAILS---------------\n\n");
    printf("Title%.10s:  %s\n"," ",flag.title);
    printf("Artist%.10s:  %s\n"," ",flag.artist);
    printf("Album%.10s:  %s\n"," ",flag.album);
    printf("Year%.10s:  %s\n"," ",flag.year);
    printf("Music%.10s:  %s\n"," ",flag.music);
    printf("Comment%.10s:  %s\n"," ",flag.comment);
    printf("\n----------------DETAILS DISPLAYED SUCCESSFULLY---------------\n");

}
