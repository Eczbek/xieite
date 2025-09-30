#include <xte/trait/has_implicit_ctor.hpp>

struct A { explicit(false) A(int); };
struct B { explicit B(int); };

static_assert(xte::has_implicit_ctor<A, int>);
static_assert(not xte::has_implicit_ctor<B, int>);
