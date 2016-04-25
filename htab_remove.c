#include "htable.h"

void htab_remove(Htab *ht, const char *key)
{
    if(ht == NULL || key == NULL)
    {
        fprintf(stderr, "htab_remove parameters cannot be NULL\n");
        return;
    }

    unsigned index = ht->hash_func(key, ht->htab_size);
    HtabListItem *item = ht->items[index];
    HtabListItem *prev_item = NULL;

    while(item != NULL)
    {
        if(strcmp(item->key, key) == 0)
        {
            break;
        }
        prev_item = item;
        item = item->next;
    }

    if(item != NULL)
    {
        if(prev_item != NULL)
            prev_item->next = item->next;
        else
            ht->items[index] = NULL;

        item->data = 0;
        item->next = NULL;
        free(item->key);
        item->key = NULL;
        free(item);
        item = NULL;
        ht->n--;
    }
}
