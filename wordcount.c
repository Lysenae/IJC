// wordcount.c
// Riesenie IJC-DU2, príklad 2), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Citanie a hashovanie slov zo suboru

#include <stdio.h>
#include <stdlib.h>

#include "htable.h"
#include "io.h"

#define MAX_LEN 127
#define HTAB_SIZE 12289U
// Velkost tabulky bola zvolena pomocou clanku dostupneho na
// http://planetmath.org/goodhashtableprimes
// Zvolene cislo ma v porovnani so susednymi cislami najnizsiu chybovost.

void htab_print(const char *key, unsigned val)
{
    printf("%s\t%d\n", key, val);
}

int main()
{
    int rslt = EXIT_SUCCESS;

    Htab *ht = htab_init(HTAB_SIZE);
    if(ht == NULL)
    {
        fprintf(stderr, "word_count: Failed to allocate Hash Table\n");
        return EXIT_FAILURE;
    }

    char s[MAX_LEN];
    FILE *f = stdin;

    while(get_word(s, MAX_LEN, f) != EOF)
    {
        if(htab_lookup_add(ht, s) == NULL)
        {
            fprintf(stderr, "word_count: Failed to lookup '%s'\n", s);
            rslt = EXIT_FAILURE;
            break;
        }
    }

    if(rslt == EXIT_SUCCESS)
    {
        htab_foreach(ht, &htab_print);
    }

    htab_free(ht);

    return rslt;
}
