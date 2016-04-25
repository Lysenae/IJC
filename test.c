#include <stdio.h>
#include "htable.h"

int main(int argc, char **argv)
{
    Htab *ht = htab_init(20);
    HtabListItem *item = htab_lookup_add(ht, "abcde");
    printf("item: %s, %d\n", item->key, item->data);
    item = htab_lookup_add(ht, "abcde");
    printf("item: %s, %d\n", item->key, item->data);
    item = htab_lookup_add(ht, "abcde");
    printf("item: %s, %d\n", item->key, item->data);
    printf("n: %d\n", ht->n);
    item = htab_lookup_add(ht, "fghij");
    printf("item: %s, %d\n", item->key, item->data);
    printf("n: %d\n", ht->n);
    item = htab_lookup_add(ht, "abcde");
    printf("item: %s, %d\n", item->key, item->data);
    htab_remove(ht, "abcde");
    printf("n: %d\n", ht->n);
    item = htab_lookup_add(ht, "abcde");
    printf("n: %d\n", ht->n);
    htab_clear(ht);
    printf("clear: %d\n", ht->n);
    htab_free(ht);
    return 0;
}