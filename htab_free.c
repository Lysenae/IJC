// htab_free.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Zrusenie hashovacej tabulky

#include "htable.h"

/**
 * Zrusenie hashovacej tabulky
 * @param ht Hashovacia tabulka
 */
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
