// io.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Citanie slov zo suboru

#include "io.h"

int get_word(char *s, int max, FILE *f)
{
    if(s == NULL || f == NULL)
    {
        fprintf(stderr, "get_word: parameters cannot be NULL\n");
        return EOF;
    }

    if(max < 0)
    {
        fprintf(stderr, "get_word: negative max parameter\n");
        return EOF;
    }

    char c;
    int i=0;
    bool max_len_rached = false;

    while(true)
    {
        if(i == max)
        {
            s[i] = '\0';

            if(!max_len_rached)
            {
                fprintf(stderr, "get_word: max length reached '%s'\n", s);
                max_len_rached = true;
            }

            while(!isspace(c) && c != EOF)
            {
                c = fgetc(f);
            }

            return i;
        }

        c = fgetc(f);
        if((isspace(c) || c == EOF) && i>0)
        {
            break;
        }
        else if(isspace(c) && i==0)
        {
            continue;
        }
        else if(c == EOF && i ==0)
        {
            return EOF;
        }

        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}
