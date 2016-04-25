#include "htable.h"

unsigned hash_function(const char *key, unsigned htab_size)
{
    unsigned h = 0;
    const unsigned char *p;
    for(p = (const unsigned char*)key; *p != '\0'; p++)
        h = 65599*h + *p;
    unsigned rslt = h % htab_size;
    printf("HASH: %d\n", rslt);
    return rslt;
}
