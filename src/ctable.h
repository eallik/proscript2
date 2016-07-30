#define ATOM_TYPE 1
#define INTEGER_TYPE 2
#define FUNCTOR_TYPE 3
#define FLOAT_TYPE 4
#define BIGINTEGER_TYPE 5
#define RATIONAL_TYPE 6
#include "types.h"
#include "bihashmap.h"

word intern(int type, uint32_t hashcode, void* key1, int key2, void*(*create)(void*, int), int* isNew);
constant getConstant(word);
