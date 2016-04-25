// dynstring.c
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 4.8.4
// Kniznica poskytujuca dynamicke textove retazce

#ifndef DYNSTRING_H
#define DYNSTRING_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct string
{
    char* str;
    unsigned len;
} String;

int strInit(String *s, const char *cstr);
int strAppendC(String *s, char c);
int strPrependC(String *s, char c);
int strAppendS(String *s, const char *cstr);
int strPrependS(String *s, const char *cstr);
int strSet(String *s, const char *cstr);
int strCmp(String s, const char *cstr);
void strFree(String *s);
char* str(String s);
unsigned strLen(String s);

#endif // DYNSTRING_H
