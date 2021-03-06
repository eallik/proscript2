#include "global.h"
#include "types.h"
#include "kernel.h"

#undef ATOM
#undef FUNCTOR
#define FUNCTOR(a,b,c) word a##Functor;
#define ATOM(a,b) word a##Atom;
#include "constants"
#undef FUNCTOR
#undef ATOM

void initialize_constants()
{
#undef ATOM
#undef FUNCTOR
#define FUNCTOR(a,b,c) a##Functor = MAKE_FUNCTOR(MAKE_ATOM(b), c);
#define ATOM(a,b) a##Atom = MAKE_ATOM(b);
#include "constants"
#undef FUNCTOR
#undef ATOM
}
