#include "htable.h"

void htab_free(Htab *ht)
{
    if(ht != NULL)
    {
        htab_clear(ht);
        ht->hash_func = NULL;
        ht->htab_size = 0;
        free(ht);
        ht = NULL;
    }
}