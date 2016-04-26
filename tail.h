// tail.h
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Program na citanie poslednych n riadkov suboru

#ifndef TAIL_H
#define TAIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct string
{
    char* str;
    unsigned len;
} String;

typedef struct string_list
{
    String *arr;
    unsigned len;
} StringList;

int read_stream(String file_name, int count);
int read_lines(FILE *f, int count);

// String
int strInit(String *s, const char *cstr);
int strAppendC(String *s, char c);
int strAppendS(String *s, const char *cstr);
int strSet(String *s, const char *cstr);
int strCmp(String s, const char *cstr);
void strFree(String *s);
char* str(String s);
unsigned strLen(String s);

// StringList
int slInit(StringList *l, unsigned size);
String *slAt(StringList *l, unsigned index);
int slAppendS(StringList *l, String s);
unsigned slLen(StringList *l);
void slFree(StringList *l);

#endif // TAIL_H
