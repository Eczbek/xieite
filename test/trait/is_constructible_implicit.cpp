#include <xte/trait/is_constructible_implicit.hpp>

struct A { explicit(false) A(int); };
struct B { explicit B(int); };

static_assert(xte::is_constructible_implicit<A, int>);
static_assert(!xte::is_constructible_implicit<B, int>);
