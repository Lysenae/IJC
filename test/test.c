#include <stdio.h>
#include "htable.h"
#include "io.h"

void print(const char *key, unsigned val)
{
    printf("'%s' = %d\n", key, val);
}

int main(int argc, char **argv)
{
    /*Htab *ht = htab_init(20);
    HtabListItem *item = htab_lookup_add(ht, "abcde");
    item = htab_lookup_add(ht, "abcde");
    item = htab_lookup_add(ht, "abcde");
    item = htab_lookup_add(ht, "fghij");
    item = htab_lookup_add(ht, "abcde");
    htab_foreach(ht, &print);
    htab_remove(ht, "abcde");
    item = htab_lookup_add(ht, "abcde");
    htab_foreach(ht, &print);
    htab_clear(ht);
    htab_free(ht);
    return 0;*/

    const int max = 50;
    char s[max];
    FILE *f;
    f = fopen("lore2.txt", "r");
    int i;
    while((i = get_word(s, max, f)) != EOF)
    {
        printf("%d: %s\n", i, s);
    }

    return 0;
}
