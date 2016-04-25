#include "htable.h"

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
