// hash_function.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Hashovacia funkcia

#include "htable.h"

/**
 * Defaultna hashovacia funkcia.
 * @param key Kluc
 * @param htab_size Velkost hashovacej tabulky
 * @return Index hashovaneho prvku
 */
unsigned hash_function(const char *key, unsigned htab_size)
{
    unsigned h = 0;
    const unsigned char *p;
    for(p = (const unsigned char*)key; *p != '\0'; p++)
        h = 65599*h + *p;
    return h % htab_size;
}
