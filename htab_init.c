// htab_init.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Inicializacia HT s defaultnou hashovacou funkciou

#include "htable.h"

/**
 * Inicializacia HT s defaultnou hashovacou funkciou.
 * @param size Velkost HT
 * @return Pointer na HT alebo NULL
 */
Htab *htab_init(unsigned size)
{
    return htab_init2(size, &hash_function);
}
