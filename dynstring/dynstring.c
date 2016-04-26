// dynstring.h
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 4.8.4
// Kniznica poskytujuca dynamicke textove retazce

#include "dynstring.h"

int strInit(String *s, const char *cstr)
{
    int len = (cstr != NULL) ? strlen(cstr) : 0;

    if((s->str = (char*)malloc(len+1)) == NULL)
    {
        return EXIT_FAILURE;
    }
    else
    {
        s->len = len;
        if(cstr != NULL)
            strcpy(s->str, cstr);
        s->str[len] = '\0';
    }
    return EXIT_SUCCESS;
}

int strAppendC(String *s, char c)
{
    if(s->str != NULL)
    {
        if((s->str = (char*)realloc(s->str, s->len+2)) != NULL)
        {
            s->str[s->len] = c;
            s->len++;
            s->str[s->len] = '\0';
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int strPrependC(String *s, char c)
{
    if(s->str != NULL)
    {
        if((s->str = (char*)realloc(s->str, s->len+2)) != NULL)
        {
            s->len++;
            for(int i=s->len; i>0; i--)
            {
                s->str[i] = s->str[i-1];
            }
            s->str[0] = c;
            s->str[s->len] = '\0';
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int strAppendS(String *s, const char *cstr)
{
    int rslt;
    if(s->str != NULL)
    {
        int len = strlen(cstr) + s->len;
        char *ns = (char*)malloc(len+1);
        strcpy(ns, s->str);
        strcat(ns, cstr);
        rslt = strSet(s, ns);
        free(ns);
    }
    else
    {
        rslt = strInit(s, cstr);
    }
    return rslt;
}

int strPrependS(String *s, const char *cstr)
{
    int rslt;
    if(s->str != NULL)
    {
        int len = strlen(cstr) + s->len;
        char *ns = (char*)malloc(len+1);
        strcpy(ns, cstr);
        strcat(ns, s->str);
        rslt = strSet(s, ns);
        free(ns);
    }
    else
    {
        rslt = strInit(s, cstr);
    }
    return rslt;
}

int strSet(String *s, const char *cstr)
{
    strFree(s);
    return strInit(s, cstr);
}

int strCmp(String s, const char *cstr)
{
    return strcmp(s.str, cstr);
}

void strFree(String *s)
{
    if(s->str != NULL)
        free(s->str);

    s->str = NULL;
    s->len = 0;
}

char* str(String s)
{
    return (s.str == NULL) ? "" : s.str;
}

unsigned strLen(String s)
{
    return (s.str == NULL) ? 0 : s.len;
}
