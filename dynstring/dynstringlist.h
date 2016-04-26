// dynstringlist.h
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 4.8.4
// Kniznica poskytujuca dynamicke pole textovych retazcov

#ifndef DYNSTRINGLIST_H
#define DYNSTRINGLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "dynstring.h"

typedef struct string_list
{
    String *arr;
    unsigned len;
} StringList;

int slInit(StringList *l, unsigned size);
String *slAt(StringList *l, unsigned index);
int slAppendS(StringList *l, String s);
unsigned slLen(StringList *l);
void slFree(StringList *l);

#endif // DYNSTRINGLIST_H
