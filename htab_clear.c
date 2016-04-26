// htab_clear.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Vyprazdnenie hashovacej tabulky

#include "htable.h"

/**
 * Vyprazdnenie hashovacej tabulky.
 * @param ht Hashovacia tabulka
 */
void htab_clear(Htab *ht)
{
    HtabListItem *item = NULL;
    HtabListItem *next_item = NULL;

    for(unsigned i=0; i<ht->htab_size; i++)
    {
        item = ht->items[i];
        while(item != NULL)
        {
            next_item = item->next;
            item->data = 0;
            item->next = NULL;
            free(item->key);
            item->key = NULL;
            free(item);

            item = next_item;
            ht->n--;
        }
        ht->items[i] = NULL;
    }
}
