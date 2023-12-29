#include <stdio.h>
#include "main.h"

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        // error message to pass cla
        printf("---------------------------------------------------------------------------------------\n");
        printf("Error: ./a.out : INVALID ARGUMENTS\nUsage:\n");
        printf("To view please pass like : ./a.out -v mp3filename\n");
        printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
        printf("To get help pass like : ./a.out --help\n");

        printf("---------------------------------------------------------------------------------------\n");
        return -1;
    }

    if(strcmp(argv[1],"--help") == 0)
    {
        //display help menu
        printf("----------------------Help menu-----------------\n");
        printf("1. -v -> to view the mp3 file contents\n");
        printf("2. -e -> to edit the mp3 file contents\n");
        printf("%4s 2.1. -t -> to edit song title\n"," ");
        printf("%4s 2.2. -a -> to edit artist name\n"," ");
        printf("%4s 2.3. -A -> to edit album name\n"," ");
        printf("%4s 2.4. -y -> to edit year\n"," ");
        printf("%4s 2.5. -m -> to edit music\n"," ");
        printf("%4s 2.6. -c -> to edit comment\n"," ");
        printf("------------------------------------------------\n");

    }

    else if(strcmp(argv[1], "-v") == 0)
    {
        //view mode
        if(argc < 3)
        {
            printf("Enter valid number of arguments\nuseage :\n");          
            printf("To view please pass like : ./a.out -v mp3filename\n");
            return -1;
        }

        FILE *fptr = fopen(argv[2],"r");
        if(fptr == NULL)
        {
            perror("fopen");
            printf("File opening Failed\n");
            return -1;
        }

        if(validate_file(fptr,argv[2]) == e_v23) 
        {
            // for version 2.3
            //skipping header
            fseek(fptr, 10, SEEK_SET);
            flags flag;

            //reading the data form file
            for(int i = 0; i < 6; i++)
            {
                read_tag(&fptr,&flag);
            }

            //display data 
            print_data(flag);

        }
        else if(validate_file(fptr,argv[2]) == e_v24)
        {
            //for version 2.4
            //skipping header
            fseek(fptr, 10, SEEK_SET);
            flags flag;

            //reading the data form file
            for(int i = 0; i < 10; i++)
            {
                read_tag(&fptr,&flag);
            }

            //display data 
            print_data(flag);

        }
        else
            printf("File validation failed\n");

        fclose(fptr);
    }

    else if(strcmp(argv[1], "-e") == 0)
    {
        //edit mode
        if(argc < 5)
        {
            printf("Enter valid number of arguments \nUsage :\n");
            printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
            return -1;
        }

        FILE *fptr = fopen(argv[4], "r+");
        if(fptr == NULL)
        {
            perror("fopen");
            printf("File opening in edit mode failed\n");
            return -1;
        }

        if(validate_file(fptr,argv[4]) != e_failure)
        {
            //skipping header
            fseek(fptr, 10, SEEK_SET);

            printf("Editmode open\n");
            edit_tag_data(&fptr, argv);
        }
        else
        {
            printf("Validation failed in edit mode\n");
            return -1;
        }

    }

}
