#include "main.h"


status validate_file(FILE *fptr,char *file)
{

    if(strcmp(strchr(file,'.'),".mp3") == 0)
    {
        fseek(fptr, 0, SEEK_SET);

        char str[4];
        fread(str,1,3,fptr);

        if(strcmp(str,"ID3") == 0)
        {

            char ver[2];
            fread(ver,1,2,fptr);

            if((ver[0] == 0x03 || ver[0] == 0x04)  && ver[1] == 0x00)
            {
                if(ver[0] == 0x03)
                {
                    return e_v23;
                }
                else if(ver[0] == 0x04)
                {
                    return e_v24;
                }
            }
            else 
            {
                printf("Unsupported version\n");
                return e_failure;
            }
        }
        else 
        {
            printf("Unsupported id\n");
            return e_failure;
        }
    }
    else
    {
        printf("Enter (.mp3) files only\n");
        return e_failure;
    }


}
