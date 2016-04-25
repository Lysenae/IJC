#include "htable.h"

Htab *htab_init(unsigned size)
{
    return htab_init2(size, &hash_function);
}
