#include <xte/trait/is_implicit_constructible.hpp>

struct A { explicit(false) A(int); };
struct B { explicit B(int); };

static_assert(xte::is_implicit_constructible<A, int>);
static_assert(!xte::is_implicit_constructible<B, int>);
