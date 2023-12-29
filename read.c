#include <stdio.h>
#include "main.h"


void read_tag(FILE **fptr, flags *flag)
{
    char tag_name[5],size[5],fl[4];
    //reading tag name
    fread(tag_name, 1, 4, *fptr);
    tag_name[4] = '\0';

    //reading size
    fread(size, 1, 4, *fptr);
    size[4] = '\0';

    //converting size into integer
    int data_size = (size[0] << 24) | (size[1] << 16) | (size[2] << 8) | size[3];

    //reading flag
    fread(fl, 1, 3, *fptr);
    //reading data 
    char tag_data[data_size+1];
    fread(tag_data, 1, data_size-1, *fptr);
    tag_data[data_size] = '\0';


    if(strcmp(tag_name,"TCON") == 0 || strcmp(tag_name, "TCOM") == 0)
    {
        flag->music = malloc(data_size);
        strcpy(flag->music,tag_data);
        flag->music[data_size-1] = '\0';
    }
    else if(strcmp(tag_name, "TALB") == 0)
    {
        flag->album = malloc(data_size);
        strcpy(flag->album,tag_data);
        flag->album[data_size-1] = '\0';
    }
    else if(strcmp(tag_name, "TIT2") == 0)
    {
        flag->title = malloc(data_size);
        strcpy(flag->title,tag_data);
        flag->title[data_size-1] = '\0';
    }
    else if(strcmp(tag_name, "TPE1") == 0)
    {
        flag->artist = malloc(data_size);
        strcpy(flag->artist,tag_data);
        flag->artist[data_size-1] = '\0';
    }
    else if(strcmp(tag_name, "COMM") == 0 || strcmp(tag_name,"TCOP") == 0)
    {
        flag->comment = malloc(data_size);
        strcpy(flag->comment,tag_data);
        flag->comment[data_size-1] = '\0';
    }
    else if((strcmp(tag_name, "TYER") == 0) || strcmp(tag_name,"TDRC") == 0)
    {
        flag->year = malloc(data_size+1);
        strcpy(flag->year,tag_data);
        flag->year[data_size-1] = '\0';
    }

}
