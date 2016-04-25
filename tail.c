// tail.c
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 4.8.4
// Program na citanie poslednych n riadkov suboru

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Vlastne pomocne struktury
#include "dynstring.h"
#include "dynstringlist.h"

int read_lines(FILE *f, int count)
{
    char c;
    String s;
    StringList sl;
    strInit(&s, NULL);
    slInit(&sl, 0);
    int i=0;
    int rslt;

    while((c = fgetc(f)) != EOF)
    {
        rslt = strAppendC(&s, c);
        if(rslt == EXIT_SUCCESS && c == '\n')
        {
            rslt = slAppendS(&sl, s);
            if(rslt == EXIT_SUCCESS)
            {
                rslt = strSet(&s, "");
            }
        }

        if(rslt == EXIT_FAILURE)
        {
            break;
        }
    }

    // Poledny riadok
    rslt = slAppendS(&sl, s);

    if(rslt == EXIT_SUCCESS)
    {
        int lines = slLen(&sl);
        if(count > lines)
        {
            count = lines;
        }

        for(int i=(lines-count), j=1; i<lines; i++, j++)
        {
            String *tmp = slAt(&sl, i);
            printf("%s", str(*tmp));
        }
    }
    else
    {
        fprintf(stderr,"Failed to read lines from file '%s'\n", str(file_name));
    }

    slFree(&sl);
    strFree(&s);
    return rslt;
}

int read_stream(String file_name, int count)
{
    FILE *f;
    int rslt;

    if(strCmp(file_name, "") == 0)
    {
        f = stdin;
        rslt = read_lines(f, count);
    }
    else
    {
        f = fopen(str(file_name), "r");
        if(f != NULL)
        {
            rslt = read_lines(f, count);
            fclose(f);
        }
        else
        {
            fprintf(stderr,"Failed to open file '%s'\n", str(file_name));
            return EXIT_FAILURE;
        }
    }

    return rslt;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);

    String file_name;
    strInit(&file_name, NULL);
    int n;

    if(argc == 1)
    {
        n = 10;
    }
    else if(argc == 2)
    {
        strSet(&file_name, argv[1]);
        n = 10;
    }
    else if(argc == 3 || argc == 4)
    {
        if(strcmp(argv[1], "-n") == 0)
        {
            for(int i=0; i<strlen(argv[2]); i++)
            {
                if(!isdigit(argv[2][i]))
                {
                    fprintf(stderr,"Invalid format of number of lines\n");
                    return EXIT_FAILURE;
                }
            }
            n = atoi(argv[2]);
        }
        else
        {
            fprintf(stderr,"Invalid argument %s\n", argv[1]);
            return EXIT_FAILURE;
        }

        if(argc == 4)
            strSet(&file_name, argv[3]);
    }
    else
    {
        fprintf(stderr,"Invalid number of arguments\n");
        return EXIT_FAILURE;
    }

    int rslt = read_stream(file_name, n);

    return rslt;
}
