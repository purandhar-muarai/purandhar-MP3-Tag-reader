#include "main.h"

void edit_tag_data(FILE **fptr, char **argv)
{
    printf("-------------------------Selected Edit Details------------------------------\n\n");
    printf("------------Selected Edit Option------------------------\n\n");

    char tag[5],size[5],flag[4];

    while(fread(tag, 1, 4, *fptr) == 4)
    {
        tag[4] = '\0';

        fread(size,1,4,*fptr);
        size[4] = '\0';
        int data_size = (size[0] << 24) | (size[1] << 16) | (size[2] << 8) | size[3];
        fread(flag,1,3, *fptr);

        if(strcmp(argv[2], "-t") == 0 && strcmp(tag, "TIT2") == 0)
        {
            //edit title tit2
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Title---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Title Changed Sucessfylly-----------------------------\n");
            break;

        }
        else if(strcmp(argv[2], "-a") == 0 && strcmp(tag, "TPE1") == 0)
        {
            //edit artist name tpe1
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Artist---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Artist Changed Sucessfylly-----------------------------\n");
            break;
        }
        else if(strcmp(argv[2], "-A") == 0 && strcmp(tag, "TALB") == 0)
        {
            //edit album name Talb
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Album---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Album Changed Sucessfylly-----------------------------\n");
            break;
        }
        else if(strcmp(argv[2], "-y") == 0 && (strcmp(tag, "TYER") == 0 || strcmp(tag, "TDRC") == 0))
        {
            //edit year TYER / TDRC
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Year---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Year Changed Sucessfylly-----------------------------\n");
            break;
        }
        else if(strcmp(argv[2], "-m") == 0 && (strcmp(tag, "TCON") == 0 || strcmp(tag, "TCOM") == 0))
        {
            //edit music TCON / TCOM
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Music---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Music Changed Sucessfylly-----------------------------\n");
            break;
        }
        else if(strcmp(argv[2], "-c") == 0 && (strcmp(tag, "TCOP") == 0 || strcmp(tag, "COMM") == 0))
        {
            //edit comment COMM/ TCOP
            fwrite(argv[3], 1, data_size-2, *fptr);
            printf("----------------Change The Comment---------------------------\n\n");
            printf("Title   : %s\n",argv[3]);
            printf("\n-----------------Comment Changed Sucessfylly-----------------------------\n");
            break;
        }
        fseek(*fptr, data_size-1, SEEK_CUR);
    }
}

