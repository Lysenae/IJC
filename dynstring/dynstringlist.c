// dynstringlist.c
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 4.8.4
// Kniznica poskytujuca dynamicke pole textovych retazcov

#include "dynstringlist.h"

int slInit(StringList *l, unsigned size)
{
    if(size > 0)
    {
        if((l->arr = malloc(size * sizeof(String))) != NULL)
        {
            for(int i=0; i<size; i++)
            {
                strInit(&(l->arr[i]), "");
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        l->arr = NULL;
    }
    l->len = size;
    return EXIT_SUCCESS;
}

String *slAt(StringList *l, unsigned index)
{
    if(index <= l->len)
    {
        return &(l->arr[index]);
    }
    else
    {
        fprintf(stderr,"slSetAt: Index %d out of range!\n", index);
        return NULL;
    }
}

int slAppendS(StringList *l, String s)
{
    if(l->len > 0)
    {
        if((l->arr = realloc(l->arr, (l->len+1) * sizeof(String))) != NULL)
        {
            strInit(&(l->arr[l->len]), str(s));
            l->len++;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        slInit(l, 1);
        strSet(&(l->arr[0]), str(s));
    }
    return EXIT_SUCCESS;
}

unsigned slLen(StringList *l)
{
    return l->len;
}

void slFree(StringList *l)
{
    for(int i=0; i<l->len; i++)
    {
        strFree(&(l->arr[i]));
    }
    free(l->arr);
    l->arr = NULL;
    l->len = 0;
}
