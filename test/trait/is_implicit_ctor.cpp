#include <xte/trait/is_implicit_ctor.hpp>

struct A { explicit(false) A(int); };
struct B { explicit B(int); };

static_assert(xte::is_implicit_ctor<A, int>);
static_assert(!xte::is_implicit_ctor<B, int>);
