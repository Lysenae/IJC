#ifndef HTABLE_H
#define HTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned (*hash_fun_ptr)(const char*, unsigned);

typedef struct htab_listitem
{
    char *key;
    unsigned data;
    struct htab_listitem *next;
} HtabListItem;

typedef struct htab
{
    unsigned htab_size;
    hash_fun_ptr hash_func;
    unsigned n;
    HtabListItem *items[];
} Htab;

Htab *htab_init(unsigned size);
Htab *htab_init2(unsigned size, hash_fun_ptr hash_fun);
HtabListItem *htab_lookup_add(Htab *ht, const char *key);
void htab_remove(Htab *ht, const char *key);
void htab_clear(Htab *ht);
void htab_free(Htab *ht);


unsigned hash_function(const char *key, unsigned htab_size);

# endif // HTABLE_H
