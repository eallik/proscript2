#define ATOM_TYPE 1
#define INTEGER_TYPE 2
#define FUNCTOR_TYPE 3
#define FLOAT_TYPE 4
#define BIGINTEGER_TYPE 5
#define RATIONAL_TYPE 6
#define BLOB_TYPE 7
#define SMALLINT_TYPE 8
#define TOMBSTONE_TYPE 0xffffffff
#include "types.h"
#include "options.h"
#include "bihashmap.h"

word intern(int type, uint32_t hashcode, void* key1, int key2, void*(*create)(void*, int), int* isNew);
word intern_blob(const char* type, void* ptr, char* (*portray)(char*, void*, Options*, int, int*));
cdata getConstant(word t, int* type);
void deleteConstant(word t, int* type);
int getConstantType(word t);
void ctable_check();
void delete_constant(word w, int type);
