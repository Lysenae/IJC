// htab_foreach.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Foreach

#include "htable.h"

/**
 * Vykonanie funkcie pre kazdy prvok HT.
 * @param ht Hashovacia tabulka
 * @param func Pointer na funkciu s parametrami const char* a unsigned
 */
void htab_foreach(Htab *ht, htable_foreach_fun func)
{
    if(ht == NULL || func == NULL)
    {
        fprintf(stderr, "htab_foreach: parameters cannot be NULL\n");
        return;
    }

    for(unsigned i=0; i<ht->htab_size; i++)
    {
        for(HtabListItem *item=ht->items[i]; item!=NULL; item=item->next)
        {
            func(item->key, item->data);
        }
    }
}
