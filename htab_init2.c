// htab_init2.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Inicializacia HT so specifickou hashovacou funkciou

#include "htable.h"

/**
 * Inicializacia HT so pecifickou hashovacou funkciou.
 * @param size Velkost HT
 * @param hash_fun Pointer na hashovaciu funkciu s parametrami const char* a
 * unsigned
 * @return Pointer na HT alebo NULL
 */
Htab *htab_init2(unsigned size, hash_fun_ptr hash_fun)
{
    Htab *ht = malloc(sizeof(*ht) + size * sizeof(HtabListItem*));
    if(ht != NULL)
    {
        ht->htab_size = size;
        ht->hash_func = hash_fun;
        ht->n = 0;

        for(unsigned i=0; i<size; i++)
        {
            ht->items[i] = NULL;
        }
    }
    return ht;
}
